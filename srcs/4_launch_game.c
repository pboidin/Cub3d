#include "../includes/cub.h"

int		ft_next_frame(void *struc)
{
	t_game	*game;

	game = struc;
	game->mlx.img.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			game->disp.reso.width, game->disp.reso.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.img_ptr,
			&game->mlx.img.bpp, &game->mlx.img.size_l,
			&game->mlx.img.endian);
	ft_updating(game);
	ft_drawing(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->mlx.img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
	return (1);
}

int		ft_launch_game(t_game *game) // Fonction qui démarre le jeu. Appelée une fois que le .cub a été analysé pour vérification et stockage des paramètres.
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (EXIT_FAILURE);
	mlx_get_screen_size(game->mlx.mlx_ptr, &game->disp.reso.width, &game->disp.reso.height); // Recupere la taille de l'ecran
	game->disp.reso.width = 960;
	game->disp.reso.height = 720;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->disp.reso.width, game->disp.reso.height, "Cub3d");
	if (!game->mlx.win_ptr)
		return (EXIT_FAILURE);;
	ft_game_init(game);
	mlx_loop_hook(game->mlx.mlx_ptr, ft_next_frame, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}