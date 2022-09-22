#include "../includes/cub.h"

int		check_extension(char *file, char *extension)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(extension);
	if (len_file <= len_ext)
		return (0);
	else if (!ft_strncmp(&file[len_file - len_ext], extension, len_ext + 1))
		return (1);
	else
		return (0);
}

void	check_arguments(int ac, char **av)
{
	if ((ac == 2) && !check_extension(av[1], ".cub"))
	{
		printf("Error\nScene description file with wrong extention.\n");
		exit(EXIT_SUCCESS);
	}
	if (ac != 2)
	{
		printf("Error\nWrong number of arguments.\n");
		exit(EXIT_SUCCESS);
	}
}
