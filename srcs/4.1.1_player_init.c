#include "../includes/cub.h"

double	ft_start_orient(char orient)
{
	double	rad;

	rad = 0;
	if (orient == 'N')
		rad = deg_transform(270);
	else if (orient == 'S')
		rad = deg_transform(90);
	else if (orient == 'W')
		rad = deg_transform(180);
	else if (orient == 'E')
		rad = deg_transform(360);
	return (rad);
}

void	ft_start_position(char **map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				player->rot_ang = ft_start_orient(map[i][j]);
				map[i][j] = '0'; // On affecte 0 à la position de départ pour simplifier la lecture de la map
			}
		}
		
	}
}

void	ft_init_player(t_game *game)
{
    game->player.walk_dir = 0; // Valeur qui sera mise à jour en fonction de la touche pressée -1 pour arrière, 1 pour avant et 0 pour immobile
    game->player.speed = 0.15; // Nombre de pixels par image entre deux positions
    game->player.turn_dir = 0; // Valeur qui sera mise à jour en fonction de la touche pressée -1 pour la gauche, 1 pour la droite et 0 pour l'immobilité
    game->player.rot_speed = deg_transform(4); // Numbers of angles per frame turned
    ft_start_position(game->disp.map.map, &game->player);
}