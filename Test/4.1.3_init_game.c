#include "cub.h"

void	ft_load_text(void *mlx, t_text *texture)
{
	texture->img_tex.img_ptr = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->width, &texture->height);
	texture->img_tex.data = (int *)mlx_get_data_addr(texture->img_tex.img_ptr,
			&texture->img_tex.bpp, &texture->img_tex.size_l,
			&texture->img_tex.endian);
}

void	ft_set_rays(t_game *game)
{
	game->rays.arr = malloc(sizeof(t_ray) * game->disp.reso.width); // Nombre de rayons = largeur de la résolution. Chaque rayon est représenté par un t_ray
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->rays.angle_view = deg_transform(VIEW_ANGLE);
	game->rays.dist_proj = (game->disp.reso.width / 2) / tan(game->rays.angle_view / 2); // Formule de la distance au plan de projection. Nous formons un rectangle entre le joueur et le plan de projection. résol.largeur / 2 = opposé du triangle, FOV / 2 = angle de ce triangle, adjacent = opposé / tan(FOV / 2). Ici, adjacent représente la distance au plan de projection.
}

void	ft_init_game(t_game *game) // Une grande partie de la mise en place ne peut se faire qu'une fois que le mlx_init a été fait.
{
	ft_set_rays(game);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.NO_tex);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.SO_tex);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.WE_tex);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.EA_tex);
}