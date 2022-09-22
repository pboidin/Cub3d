#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;
	(void)argc;
	check_arguments(argc, argv); //Il faut y mettre ton check ici
	fd = open(argv[1], O_RDONLY); 
	if (fd == -1)
	{
		printf("Error\nCould not open file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	ft_init_struct(fd, &game.disp); // Il s'agit de l'init ici
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	ft_check_map(&game.disp);
	ft_launch_game(&game);
	return (0);
}