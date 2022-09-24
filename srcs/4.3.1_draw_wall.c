#include "../includes/cub.h"

t_text	ft_get_wall_tex(t_disp *disp, char orienta)
{
	if (orienta == 'N')
		return (disp->NO_tex);
	else if (orienta == 'S')
		return (disp->SO_tex);
	else if (orienta == 'W')
		return (disp->WE_tex);
	else
		return (disp->EA_tex);
}

int		ft_get_y_wall_pos(t_game *game, double wall_hei) // Obtient la position verticale du début du mur.
{
	double	screen_cent;
	double	wall_cent;
	int		y;

	screen_cent = game->disp.reso.height / 2; // Je vais au centre horizontal de l'écran
	wall_cent = wall_hei / 2; // Comme je sais que le mur sera centré horizontalement, il me suffit de ajouter la moitié de la hauteur du mur pour trouver où il doit commencer.
	y = screen_cent - wall_cent;
	if (y < 0) // Cas limite : Je suis si près du mur que sa hauteur est supérieure à la hauteur de l'écran. que la hauteur de l'écran, il commence à s'afficher en haut de l'écran.
		y = 0;
	return (y);
}

double	ft_get_hei_wall(t_game *game, t_ray *ray) // Obtient la hauteur du mur
{
	double	wall_hei;
	double	scal_dis;
	double	adju_fish;

	adju_fish = cos(ray->angle - game->player.rot_ang); // L'implémentation euclidienne de la diffusion de rayons souffre de l'inhérent effet fisheye. Ceci le corrige
	scal_dis = ray->size * SCALE * adju_fish; // Passe de la distance de la grille à la distance de la pleine échelle
	wall_hei = (SCALE / (scal_dis)) * game->rays.dist_proj;
	return (wall_hei);
}

void	ft_draw_wall(t_game *game) // Dessine les murs une colonne à la fois
{
	int		i;
	double	wall_hei;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->disp.reso.width)
	{
		ray = &game->rays.arr[i];
		wall_hei = ft_get_hei_wall(game, ray);
		rect.x = i;
		rect.y = ft_get_y_wall_pos(game, wall_hei);
		rect.hei = wall_hei;
		rect.tex = ft_get_wall_tex(&game->disp, ray->orienta);
		ft_draw_strip_w(&rect, game->mlx.img.data, &game->disp.reso, ray);
	}
}