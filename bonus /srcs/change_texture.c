#include "../includes/cub.h"

void	ft_change_texture2(game_t *game, int key)
{
	if (key == NORTH)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_NO,
				&game->bits_per_pixel_tex,
				&game->line_length_tex, &game->endian_tex);
	}
	else if (key == SOUTH)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_SO,
				&game->bits_per_pixel_tex,
				&game->line_length_tex, &game->endian_tex);
	}
}

int		ft_change_texture(game_t *game)
{
	if (game->orientation == NORTH && game->side == 1)
	{
		ft_change_texture2(game, NORTH);
		return (0);
	}
	else if (game->orientation == SOUTH && game->side == 1)
	{
		ft_change_texture2(game, SOUTH);
		return (0);
	}
	else if (game->orientation == EAST && game->side == 2)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_EA,
				&game->bits_per_pixel_tex,
				&game->line_length_tex, &game->endian_tex);
		return (0);
	}
	else if (game->orientation == WEST && game->side == 2)
	{
		game->addr_tex = mlx_get_data_addr(game->texture_WE,
				&game->bits_per_pixel_tex,
				&game->line_length_tex, &game->endian_tex);
		return (0);
	}
	return (0);
}