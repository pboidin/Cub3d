#include "../includes/cub.h"

int	ft_exit(void)
{
	exit(EXIT_FAILURE);
}

void	main2(game_t *game, info_t *info)
{
	game_init(game, info);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	position_map_player(game); // donne une position sur la map
	raycasting(game);
	ft_gun(game, GUN_TEXT);
}

int 	main(int argc, char ** argv)
{
	game_t	game;
	info_t	info;
	char	**file;

	init_var(&game.is_shot, &game.x_mouse);
	file = ft_check_args(argc, argv); // Créer une fonction qui va checker les arguments
	game.map = game_in(file); // Function qui check l'information transmise par .cub
	// Créer une fonction qui va vérifier l'intégrité de la map
	info_init(&info, file);
	if ((game.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((game.win_ptr = mlx_new_window(game.mlx_ptr, DIS_WID, DIS_HEI, "Cub3D")) == NULL)
		return (EXIT_FAILURE);
	main2(&game, &info);
	mlx_hook(game.win_ptr, 2, 1L << 0, player_move, &game);
	mlx_hook(game.win_ptr, 3, 1L << 1, ft_shoot, &game);
	mlx_loop_hook(game.mlx_ptr, check_itera, &game);
	//créer systeme souris
	mlx_hook(game.win_ptr, 17, 0, ft_exit, NULL);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
