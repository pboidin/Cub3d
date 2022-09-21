#include "cub.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;
	(void)argc;
	check_arguments(argc, argv);//Attente
	fd = open(argv[1], O_RDONLY); 
	if (fd == -1)
	{
		printf("Error\nCould not open file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	//get_scene(fd, &game.disp); //Attente
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file %s.\n", argv[1]);
		exit(EXIT_SUCCESS);
	}
	//check_scene(&game.disp); //Attente
	ft_launch_game(&game);
	return (0);
}