#include "../includes/cub.h"

void    init_tmp(int *tmp, int *v)
{
    (*tmp) = 380;
    (*v) = 0;
}

void    ft_clear(game_t *game)
{
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
    mlx_destroy_image(game->mlx_ptr, game->img);
    game->img = mlx_new_image(game->mlx_ptr, 960, 700);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
}

void    ft_shoot2(game_t *game, int *x, int *y, int *tmp_y)
{
    *x = 0;
    *y = 0;
    *tmp_y = 500;
    ft_clear(game);
    raycasting(game);
    game->img_gun = mlx_xpm_file_to_image(game->mlx_ptr, GUN2_TEXT, &game->hei_tex, &game->wid_tex);
    game->char_gun = mlx_get_data_addr(game->img_gun, &game->bits, &game->lines, &game->endi);
}

int		ft_shoot(game_t *game, int key)
{
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;
	char	*p;

	if (key == F)
	{
		ft_shoot2(game, &x, &y, &tmp_y);
        while (tmp_y <= 700)
        {
            init_tmp(&tmp_x, &x);
            while (tmp_x < 580)
            {
                p = game->char_gun + ((y * game->lines + x * (game->bits / 8)));
                if (*(unsigned int *) p != 4278190080)
                    my_mlx_put_pxl(game, tmp_x, tmp_y, *(unsigned int *)p);
                ft_increment(&x, &tmp_x);
            }
            ft_increment(&y, &tmp_y);
        }
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
        game->is_shot = 1;
    }
    return (0);
}