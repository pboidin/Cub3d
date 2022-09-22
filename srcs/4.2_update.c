#include "../includes/cub.h"

void	ft_upd_rays(t_game *game)
{
	double	angle_ray;
	int		i;

	angle_ray = game->player.rot_ang - game->rays.angle_view / 2;
	i = -1;
	while (++i < game->disp.reso.width)
	{
		game->rays.arr[i].angle = angle_ray;
		ft_raycast(&game->rays.arr[i], &game->disp.map, &game->player);
		angle_ray += game->rays.angle_view / game->disp.reso.width;
	}
}

void	ft_upd_player_ori(t_player *player) // Mise à jour de la rotation du joueur en fonction des clics de la flèche gauche/droite.
{
	double	rot;

	if (player->turn_dir == 0) // Le joueur n'appuie pas sur les flèches gauche et droite.
		return ;
	rot = player->turn_dir * player->rot_speed; // La largeur de la rotation dépend de la vitesse de rotation.
	player->rot_ang += rot; // La largeur de la rotation dépend de la vitesse de rotation. La direction de la rotation est -1 si elle est à gauche et +1 si elle est à droite.
}


void	ft_upd_player_pos(char **grid, t_player *player) // Mise à jour de la position du joueur en fonction du mouvement du WASD.
{
	double	rot;
	double	move;

	if (player->walk_dir == 0) // l'utilisateur n'a pas appuyé sur WASD
		return ;
	move = player->speed; // Déplacement vers l'avant (pression de la touche W). Cas par défaut car si une autre touche que W est pressée, une ou les deux valeurs seront écrasées.
	rot = player->rot_ang;
	if (player->walk_dir == 's') // Retour en arrière (appui sur la touche S). Même orientation mais dans le sens inverse
		move = (-1) * player->speed;
	else if (player->walk_dir == 'a') // Déplacement vers la gauche (appui sur la touche A). Nous regardons à droite et nous nous déplaçons vers l'arrière
	{
		move = (-1) * player->speed;
		rot = player->rot_ang + deg_transform(90);
	}
	else if (player->walk_dir == 'd') // Avancer vers la droite (appui sur la touche D). Nous regardons à droite et avançons
		rot = player->rot_ang + deg_transform(90);
	player->x += cos(rot) * move; // Ajoutant à x le adjacent (aller à gauche...)
	player->y += sin(rot) * move; // Ajoutant à y le contraire (...et plus)
	if (ft_strchr("1", grid[(int)player->y][(int)player->x])) // Si la nouvelle position est dans un mur, nous revenons à la position précédente. position précédente
	{
		player->x -= cos(rot) * move;
		player->y -= sin(rot) * move;
	}
}

void	ft_updating(t_game *game) // À chaque image, nous vérifions si les valeurs de nos structures doivent être mises à jour en raison des interactions de l'utilisateur (mouvements de la souris ou pressions sur les touches). 
{
	ft_upd_player_pos(game->disp.map.map, &game->player);
	ft_upd_player_ori(&game->player);
	ft_upd_rays(game);
}