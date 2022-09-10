#include "../includes/cub.h"

void	ft_upd_angle_player(game_t *game, int key)
{
	if (key == LFT)
	{
		game->angle -= 0.20;
		if (game->angle < 0)
			game->angle += 2 * PI;
	}
	else if (key == RT)
	{
		game->angle += 0.20;
		if (game->angle > 2 * PI)
			game->angle = (game->angle - (2 * PI));
	}
}

void    ft_upd_coo_player(game_t *game, int key)
{
    if (key == W)
        check_up_button(game);
    else if (key == S)
        check_down_button(game);
    else if (key == A)
        check_left_button(game);
    else if (key == D)
        check_right_button(game);
}

int player_move(int key, game_t *game)
{
    if (key == A || key == S || key == D || key == W || key == LFT || key == RT || key == ESC)
    {
        mlx_clear_window(game->mlx_ptr, game->win_ptr);
        mlx_destroy_image(game->mlx_ptr, game->img);
        game->img = mlx_new_image(game->mlx_ptr, DIS_WID, DIS_HEI);
        game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
                        &game->line_length, &game->endian);
        if (key == LFT || key == RT)
            ft_upd_angle_player(game, key);
        else if (key == ESC)
        {
            mlx_destroy_window(game->mlx_ptr, game->win_ptr);
            exit(EXIT_FAILURE);
        }
        else
            ft_upd_coo_player(game, key);
        raycasting(game);
    }
    return (0);
}