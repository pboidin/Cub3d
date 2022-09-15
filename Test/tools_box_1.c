#include "cub.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		free(map->map[i]);
	}
	free(map->map);
}

void	ft_free_disp(t_disp *disp)
{
	free(disp->NO_tex.path);
	free(disp->SO_tex.path);
	free(disp->WE_tex.path);
	free(disp->EA_tex.path);
	free_map(&disp->map);
}

void	ft_free_game(t_game *game)
{
	ft_free_disp(&game->disp);
	free(game->rays.arr);
}

double	deg_transform(double deg) // Transform Deg in radian
{
	return (deg * M_PI  /180.0);
}

double	ft_radian_norm(double rad) // S'assure que le radian reste entre 0 et 2 * PI
{
	double	circle;

	circle = deg_transform(360);
	rad = fmod(rad, circle);
	if (rad < 0)
		rad += circle;
	return (rad);
}