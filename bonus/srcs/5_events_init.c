/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_events_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:43:38 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:38:23 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_close_win(int key, t_game *game)
{
	(void)key;
	(void)game;
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_key_relea(int key, t_game *game)
{
	(void)game;
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		game->player.walk_dir = 0;
	else if (key == K_LEFT_ARROW || key == K_RIGHT_ARROW)
		game->player.turn_dir = 0;
	return (1);
}


int	ft_key_press(int key, t_game *game, t_map *ma_map) // ICI
{
	(void) ma_map;
	if (key == K_W)
		game->player.walk_dir = 'w';
	else if (key == K_A)
		game->player.walk_dir = 'a';
	else if (key == K_S)
		game->player.walk_dir = 's';
	else if (key == K_D)
		game->player.walk_dir = 'd';
	else if (key == K_LEFT_ARROW)
		game->player.turn_dir = -1;
	else if (key == K_RIGHT_ARROW)
		game->player.turn_dir = 1;
	else if (key == K_ESC)
	{
		ft_free_game(game);
		mlx_destroy_image(game->mlx.mlx_ptr, game->disp.no_tex.img_tex.img_ptr);
		mlx_destroy_image(game->mlx.mlx_ptr, game->disp.so_tex.img_tex.img_ptr);
		mlx_destroy_image(game->mlx.mlx_ptr, game->disp.we_tex.img_tex.img_ptr);
		mlx_destroy_image(game->mlx.mlx_ptr, game->disp.ea_tex.img_tex.img_ptr);
		// mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		mlx_destroy_display(game->mlx.mlx_ptr);
		// ft_exit(ma_map, ma_map->map);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

void	ft_init_events(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.mlx_ptr);
	mlx_hook(game->mlx.win_ptr, KEY_PRESS, M_KEY_PRESS, ft_key_press, game);
	mlx_hook(game->mlx.win_ptr, KEY_RELEASE, M_KEY_RELEASE, ft_key_relea, game);
	mlx_hook(game->mlx.win_ptr, DESTROY_NOT, M_DESTROY_NOT, ft_close_win, game);
}
