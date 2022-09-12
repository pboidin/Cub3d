#include "../includes/cub.h"

void	wait_frame(void)
{
	int	i;

	i = 0;
	while (i < 900000)
		i++;
}

int		check_itera(game_t *game)
{
	if (game->is_shot == 3)
	{
		wait_frame();
		ft_clear(game);
		raycasting(game);
		ft_gun(game, GUN_TEXT);
		game->is_shot = 0;
	}
	else if (game->is_shot == 2)
	{
		ft_clear(game);
		raycasting(game);
		ft_gun(game, GUN4_TEXT);
		game->is_shot = 3;
	}
	else if (game->is_shot == 1)
	{
		ft_clear(game);
		raycasting(game);
		ft_gun(game, GUN3_TEXT);
		game->is_shot = 2;
	}
	return (0);
}

void	ft_increment(int *v1, int *v2)
{
	(*v1)++;
	(*v2)++;
}

void	ft_gun_img(game_t *game, char *tex)
{
	game->img_gun = mlx_xpm_file_to_image(game->mlx_ptr, tex, &game->hei_tex, &game->wid_tex);
	game->char_gun = mlx_get_data_addr(game->img_gun, &game->bits, &game->lines, &game->endi);
}

void	ft_gun(game_t *game, char *tex)
{
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;
	char	*p;

	ft_gun_img(game, tex);
	tmp_y = 500;
	y = 0;
	while (tmp_y <= 700)
	{
		tmp_x = 380;
		x = 0;
		while (tmp_x <= 580)
		{
			p = game->char_gun + ((y * game->lines + x * (game->bits / 8)));
			if (*(unsigned int *)p != 4278190080)
				my_mlx_put_pxl(game, tmp_x, tmp_y, *(unsigned int *)p);
			ft_increment(&x, &tmp_x);
		}
		ft_increment(&y, &tmp_y);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
}