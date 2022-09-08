#include "cub.h"

void	ft_change_1(game_t *game, int cardi)
{
	if (cardi == NORTH)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_NO,
					&game->bits_per_pixel,
					&game->line_lenght, &game->endian);
	}
	else if (cardi == SOUTH)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_SO,
					&game->bits_per_pixel,
					&game->line_lenght, &game->endian);
	}
}

int		ft_change_texture(game_t *game)
{
	if (game->orientation == NORTH && game->side == 1)
	{
		ft_change_1(game, NORTH);
		return (0);
	}
	else if (game->orientation == SOUTH && game->side == 1)
	{
		ft_change_1(game, SOUTH);
		return (0);
	}
	else if (game->orientation == WEST && game->side == 2)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_WE,
					&game->bits_per_pixel,
					&game->line_lenght, &game->endian);
		return (0);
	}
	else if (game->orientation == EAST && game->side == 2)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_EA,
					&game->bits_per_pixel,
					&game->line_lenght, &game->endian);
		return (0);
	}
	return (0);
}