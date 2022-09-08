#include "cub.h"

void    ft_check_move2(game_t *game, float *tmp_x, float *tmp_y)
{
	(*tmp_x) = game->x_player;
	(*tmp_y) = game->y_player;
}

int     ft_check_moves(game_t *game, float angle)
{
	int		i;
	float	tmp_x;
	float	tmp_y;
	float	tmp_angle;

	tmp_angle = angle + 0.523598;
	while (angle <= tmp_angle)
	{
		i = 0;
		ft_check_move2(game, &tmp_x, &tmp_y);
		while (i < 60)
		{
			if (lroundf(tmp_x) % 60 == 0
				&& check_x_axis(game, lroundf(tmp_x), lroundf(tmp_y)))
				return (-1);
			else if (lroundf(tmp_y) % 60 == 0
				&& check_y_axis(game, lroundf(tmp_x), lroundf(tmp_y)))
				return (0);
			tmp_x += cos(angle);
			tmp_y += sin(angle);
			i++;
		}
		angle += 0.07;
	}
	return (1);
}

void	check_up_button(game_t *game)
{
	if (ft_check_moves(game, game->angle - 0.261799) == 1)
	{
		game->x_player += cos(game->angle) * 15;
		game->y_player += sin(game->angle) * 15;
	}
	else if (ft_check_moves(game, game->angle - 0.261799) == -1)
	{
		if (game->angle >= 0 && game->angle <= M_PI
			&& ft_check_moves(game, 1.308991) != 0)
			game->y_player += sin(game->angle) * 15;
		else if (game->angle >= M_PI
			&& ft_check_moves(game, 4.7123889 - 0.261799) != 0)
			game->y_player += sin(game->angle) * 15;
	}
	else
	{
		if (game->angle <= 4.7123889 && game->angle >= M_PI / 2
			&& ft_check_moves(game, (M_PI - 0.261799)) != -1)
			game->x_player += cos(game->angle) * 15;
		else if ((game->angle >= 4.7123889 || game->angle <= M_PI / 2)
			&& ft_check_moves(game, -0.261799) != -1)
			game->x_player += cos(game->angle) * 15;
	}
}

void	check_down_butt_2(game_t *game)
{
	game->y_player -= sin(game->angle) * 15;
	game->x_player -= cos(game->angle) * 15;
}

void	check_down_button(game_t *game)
{
	float	back;

	back = game->angle + M_PI;
	if (game->angle > M_PI)
		back = game->angle - M_PI;
	if (ft_check_moves(game, back - 0.261799) == 1)
		check_down_butt_2(game);
	else if (ft_check_moves(game, back - 0.261799) == -1)
	{
		if (back >= 0 && back <= M_PI
			&& ft_check_moves(game, 1.57079 - 0.261799) != 0)
			game->y_player -= sin(game->angle) * 15;
		else if (back >= M_PI
			&& ft_check_moves(game, 4.7123889 - 0.261799) != 0)
			game->y_player -= sin(game->angle) * 15;
	}
	else
	{
		if (back <= 4.7123889 && back >= M_PI / 2
			&& ft_check_moves(game, (M_PI - 0.261799)) != -1)
			game->x_player -= cos(game->angle) * 15;
		else if ((back > 4.7123889 || back < M_PI / 2)
			&& ft_check_moves(game, -0.261799) != -1)
			game->x_player -= cos(game->angle) * 15;
	}
}

void	check_butt_2(game_t *game, float key)
{
	game->x_player += cos(key) * 15;
	game->y_player += sin(key) * 15;
}

void	check_left_button(game_t *game)
{
	float	left;

	left = game->angle - (M_PI / 2);
	if (ft_check_moves(game, left - 0.261799) == 1)
		check_butt_2(game, left);
	else if (ft_check_moves(game, left - 0.261799) == -1)
	{
		if (left >= 0 && left <= M_PI
			&& ft_check_moves(game, 1.57079 - 0.261799) != 0)
			game->y_player += sin(left) * 15;
		else if (left >= M_PI
			&& ft_check_moves(game, 4.7123889 - 0.261799) != 0)
			game->y_player += sin(left) * 15;
	}
	else
	{
		if (left <= 4.7123889 && left >= M_PI / 2
			&& ft_check_moves(game, (M_PI - 0.261799)) != -1)
			game->x_player += cos(left) * 15;
		else if ((left > 4.7123889 || left < M_PI / 2)
			&& ft_check_moves(game, -0.261799) != -1)
			game->x_player += cos(left) * 15;
	}
}

void	check_right_button(game_t *game)
{
	float	right;

	right = game->angle + (M_PI / 2);
	if (game->angle > 4.7123889)
		right = (game->angle + (M_PI / 2)) - (2 * M_PI);
	if (ft_check_moves(game, right - 0.261799) == 1)
		check_butt_2(game, right);
	else if (ft_check_moves(game, right - 0.261799) == -1)
	{
		if (right >= 0 && right <= M_PI
			&& ft_check_moves(game, 1.57079 - 0.261799) != 0)
			game->y_player += sin(right) * 15;
		else if (right >= M_PI
			&& ft_check_moves(game, 4.7123889 - 0.261799) != 0)
			game->y_player += sin(right) * 15;
	}
	else
	{
		if (right <= 4.7123889 && right >= M_PI / 2
			&& ft_check_moves(game, (M_PI - 0.261799)) != -1)
			game->x_player += cos(right) * 15;
		else if ((right > 4.7123889 || right < M_PI / 2)
			&& ft_check_moves(game, -0.261799) != -1)
			game->x_player += cos(right) * 15;
	}
}