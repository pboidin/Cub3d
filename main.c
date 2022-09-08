#include "cub.h"

int	ft_exit(void)
{
	exit(EXIT_FAILURE);
}

int main(int argc, char ** argv)
{
	game_t	game;
	info_t	info;
	char	**file;

	write(1, "1 - First step\n", 15);
	file = ft_check_args(argc, argv); // Créer une fonction qui va checker les arguments
	write(1, "2 - Check_args succeed\n", 23);
	game.map = game_in(file); // Function qui check l'information transmise par .cub
	write(1, "3 - Check game_in succeed\n", 26);
	// Créer une fonction qui va vérifier l'intégrité de la map
	write(1, "4 - Second step\n", 16);
	info_init(&info, file);
	if ((game.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((game.view_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3D")) == NULL)
		return (EXIT_FAILURE);
	game_init(&game, &info);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_lenght, &game.endian);
	position_map_player(&game); // donne une position sur la map
	raycasting(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, player_move, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_exit, NULL);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
