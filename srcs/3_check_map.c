#include "../includes/cub.h"

int		has_one_start_position(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				count++;
		}
	}
	return (count == 1);
}

int		is_map_enclosed(char **map, int hei, int wid)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i == 0 || j == 0 || i == hei - 1 || j == wid - 1)
					return (0);
				else if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' '
					|| map[i - 1][j + 1] == ' ' || map[i][j + 1] == ' '
					|| map[i + 1][j + 1] == ' ' || map[i + 1][j] == ' '
					|| map[i + 1][j - 1] == ' ' || map[i][j - 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

void	check_map(t_map *map)
{
	if (map->map == 0)
	{
		printf("Error\nThe map is missing.\n");
		exit(EXIT_SUCCESS);
	}
	else if (!is_map_enclosed(map->map, map->height, map->width))
	{
		printf("Error\nThe map is not enclosed.\n");
		exit(EXIT_SUCCESS);
	}
	else if (!has_one_start_position(map->map))
	{
		printf("Error\nThe map has 0 or more than 1 start position.\n");
		exit(EXIT_SUCCESS);
	}
}

int		create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	check_color(t_colo *color, char *name)
{
	if (color->r == -1)
	{
		printf("Error\nThe %s is either missing or poorly "
					"formatted.\n", name);
		exit(EXIT_SUCCESS);
	}
	else if (255 < color->r || 255 < color->g || 255 < color->b)
	{
		printf("Error\nThe RGB code for the %s is "
					"incorrect.\n", name);
		exit(EXIT_SUCCESS);
	}
	color->argb = create_argb(0, color->r, color->g, color->b);
}

void	check_texture(char *path, char *name)
{
	int	fd;

	if (path == 0)
	{
		printf("Error\nThe %s is either missing or poorly "
					"formatted.\n", name);
		exit(EXIT_SUCCESS);
	}
	if (!check_extension(path, ".xpm"))
	{
		printf("Error\nFile %s doesn't have xpm extension\n", name);
		exit(EXIT_SUCCESS);
	}
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		printf("Error\nCould not open the %s: "
					"%s.\n", name, path);
		exit(EXIT_SUCCESS);
	}
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file %s.\n", path);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map(t_disp *disp)
{
	check_texture(disp->NO_tex.path, "north texture");
	check_texture(disp->SO_tex.path, "south texture");
	check_texture(disp->WE_tex.path, "west texture");
	check_texture(disp->EA_tex.path, "east texture");
	check_color(&disp->floor, "floor color");
	check_color(&disp->ceilling, "ceilling color");
	check_map(&disp->map);
}