#include "../includes/cub.h"

int		check_x_axis(game_t *game, long int x, long int y)
{
	if (x <= game->x_player)
	{
		game->orientation = WEST;
		game->f_side = 10;
		x -= 60;
		while (y % 60 != 0)
			y--;
		if (game->map[y / 60][x / 60] == '1')
			return (1);
	}
	else if (x >= game->x_player)
	{
		game->orientation = EAST;
		game->f_side = 0;
		while (y % 60 != 0)
			y--;
		if (game->map[y / 60][x / 60] == '1')
			return (1);
	}
	return (0);
}

int		check_y_axis(game_t *game, long int x, long int y)
{
	if (y <= game->y_player)
	{
		game->orientation = NORTH;
		game->f_side = 0;
		y -= 60;
		while (x % 60 != 0)
			x--;
		if (game->map[y / 60][x / 60] == '1')
			return (1);
	}
	else if (y >= game->y_player)
	{
		game->orientation = SOUTH;
		game->f_side = 0;
		while (x % 60 != 0)
			x--;
		if (game->map[y / 60][x / 60] == '1')
			return (1);
	}
	return (0);
}

int		round_params_3(game_t *game, float tmp_x, float tmp_y)
{
	if (lroundf(tmp_x) % 60 == 0
			&& check_x_axis(game, lroundf(tmp_x), lroundf(tmp_y))) // Create Function
	{
		if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
				&& !(game->x_player < lroundf(tmp_x)))
			return (1);
		game->ver_inter = tmp_y;
		game->side = 2;
		return (1);
	}
	return (0);
}

int		round_params_2(game_t *game, float tmp_x, float tmp_y)
{
	if (lroundf(tmp_y) % 60 == 0
			&& check_y_axis(game, lroundf(tmp_x), lroundf(tmp_y))) // Create Function
	{
		if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0)
			return (1);
		game->hor_inter = tmp_x;
		game->side = 1;
		return (1);
	}
	return (0);
}

int		second_check_colli(game_t *game, float tmp_x, float tmp_y)
{
	long int	n;

	n = (lroundf(tmp_x) - 60) / 60;
	if (game->x_player <= tmp_x && game->y_player <= tmp_y
			&& lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
			&& (game->map[lroundf(tmp_y) / 60][lroundf(tmp_x) / 60] == '1'
			|| game->map[lroundf(tmp_y) / 60][n] == '1'
			|| game->map[(lroundf(tmp_y - 60)) / 60][lroundf(tmp_x) / 60] == '1'))
			return (1);
	return (0);
}

int		first_check_colli(game_t *game, float tmp_x, float tmp_y)
{
	long int	n;

	n = (lroundf(tmp_x) - 60) / 60;
	if (game->x_player >= tmp_x && game->y_player >= tmp_y
			&& lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
			&& (game->map[(lroundf(tmp_y) - 60) / 60][n] == '1'
			|| game->map[(lroundf(tmp_y) - 60) / 60][lroundf(tmp_x) / 60] == '1'
			|| game->map[lroundf(tmp_y) / 60][n] == '1'))
			return (1);
	return (0);
}

void	round_params(game_t *game, float tmp_x, float tmp_y)
{
		if (game->x_player <= tmp_x && game->y_player <= tmp_y
				&& lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
				&& game->map[lroundf(tmp_y) / 60][(lroundf(tmp_x) - 60) / 60] == '1'
				&& game->map[lroundf(tmp_y) / 60][lroundf(tmp_x) / 60] == '0')
		{
			game->hor_inter = tmp_x;
			game->side = 1;
			game->orientation = SOUTH;
		}
}

int		ray_touch_wall(game_t *game, float tmp_x, float tmp_y)
{
	round_params(game, tmp_x, tmp_y);
	if (first_check_colli(game, tmp_x, tmp_y) == 1)
		return (1);
	else if (second_check_colli(game, tmp_x, tmp_y) == 1)
		return (1);
	else if (round_params_2(game, tmp_x, tmp_y) == 1)
		return (1);
	else if (round_params_3(game, tmp_x, tmp_y) == 1)
		return (1);
	return (0);
}

void	ft_init_vars(int *y_axis, float *y_loop, int *wall, int height)
{
	*y_loop = 0;
	*y_axis = 0;
	*wall = (((DIS_HEI - height) / 2) + height);
}

int		coder_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_put_pxl(game_t *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_pxl_flo(game_t *game, int x, int y_axis)
{
	my_mlx_put_pxl(game, x, y_axis, coder_rgb(game->Floor_col[0],
			game->Floor_col[1], game->Floor_col[2]));
}

void	ft_put_pxl_ceil(game_t *game, int x, int y_in_axis)
{
	my_mlx_put_pxl(game, x, y_in_axis, coder_rgb(game->Ceiling_col[0],
			game->Ceiling_col[1], game->Ceiling_col[2]));
}

char	*ft_load_color(game_t *game, double screen_y)
{
	int	text_x;
	int	grid_size;
	int	text_w;
	int	text_h;
	int	text_y;

	text_x = 0;
	grid_size = 60;
	text_w = 60;
	text_h = 60;
	text_y = screen_y * text_h;
	if (game->side == 1)
		text_x = fmod(game->hor_inter / (float)grid_size, 1.0) * text_w;
	else
		text_x = fmod(game->ver_inter / (float)grid_size, 1.0) * text_w;
	return (game->addr_tex + (text_y * (game->line_length_tex) + text_x * (game->bits_per_pixel_tex / 8)));
	return (NULL);
}

void	raycast(int height, game_t *game, int x)
{
	int		y_axis;
	char	*color_pxl;
	int		wall;
	float	y_loop;

	ft_change_texture(game);
	ft_init_vars(&y_axis, &y_loop, &wall, height);
	while (y_axis <= (DIS_HEI - height) / 2)
	{
		ft_put_pxl_ceil(game, x, y_axis);
		y_axis++;
	}
	while (y_axis < wall)
	{
		color_pxl = ft_load_color(game, (1.0 - ((float)(wall - y_axis) / (float)height)));
		my_mlx_put_pxl(game, x, y_axis, *(unsigned int *)color_pxl);
		y_axis++;
	}
	while (y_axis < DIS_HEI)
	{
		ft_put_pxl_flo(game, x, y_axis);
		y_axis++;
	}
	x++;
}

void	put_wall(game_t *game, float tmp_x, float tmp_y, float ray_angle)
{
	float	fisheyes;
	float	dist_2D;
	float	height;
	float	y_offset;

	game->nb_rays++;
	dist_2D = 0;
	dist_2D = sqrt(pow(tmp_x - game->x_player, 2) + pow(game->y_player - tmp_y, 2));
	fisheyes = dist_2D * cos(ray_angle - game->angle);
	height = ((60 * DIS_HEI) / fabs(fisheyes));
	if (height > DIS_HEI)
	{
		y_offset = (height - DIS_HEI) / 1.0;
		height -= y_offset;
	}
	if (game->nb_rays <= DIS_WID)
		raycast(height, game, game->x_prime);
	game->x_prime += 1;
}

void	raycasting(game_t *game)
{
	float	tmp_x;
	float	tmp_y;
	float	ray_angle;

	ray_angle = game->angle - 0.5235988;
	init_var(&game->x_prime, &game->nb_rays); // J'initialise à 0
	while (ray_angle <= game->angle + 0.5235988)
	{
		tmp_x = game->x_player;
		tmp_y = game->y_player; // Je donne à tmp la position de mon joueur
		while (1)
		{
			if (ray_touch_wall(game, tmp_x, tmp_y)) // Check si le rayon touche le mur
				break;
			tmp_x += cos(ray_angle) * 0.5;
			tmp_y += sin(ray_angle) * 0.5;
		}
		put_wall(game, tmp_x, tmp_y, ray_angle);// Créer une fonction qui calcul la hauteur du mur
		ray_angle += 0.00109083333;
	}
	//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
}