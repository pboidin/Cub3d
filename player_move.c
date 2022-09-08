#include "cub.h"

void	ft_upd_angle_player(game_t *game, int key)
{
	if (key == 123)
	{
		game->angle -= 0.20;
		if (game->angle < 0)
			game->angle += 2 * PI;
	}
	else if (key == 124)
	{
		game->angle += 0.20;
		if (game->angle > 2 * PI)
			game->angle = (game->angle - (2 * PI));
	}
}

void    ft_upd_coo_player(game_t *game, int key)
{
    if (key == 13)
        check_up_button(game);
    else if (key == 1)
        check_down_button(game);
    else if (key == 0)
        check_left_button(game);
    else if (key == 2)
        check_right_button(game);
}

int player_move(int key, game_t *game)
{
    if (key == 0 || key == 1 || key == 3 || key == 13 || key == 123 || key == 124 || key == 53)
    {
        mlx_clear_window(game->mlx_ptr, game->win_ptr);
        mlx_destroy_image(game->mlx_ptr, game->img);
        game->img = mlx_new_image(game->mlx_ptr, 960, 700);
        game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
                        &game->line_lenght, &game->endian);
        if (key == 123 || key == 124)
            ft_upd_angle_player(game, key);
        else if (key == 53)
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