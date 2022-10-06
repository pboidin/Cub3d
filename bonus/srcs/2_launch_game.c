/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_launch_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:22 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/27 18:03:31 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_next_frame(void *struc)
{
	t_game	*game;

	game = struc;
	game->mlx.img.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			game->disp.reso.width,
			game->disp.reso.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.img_ptr,
			&game->mlx.img.bpp,
			&game->mlx.img.size_l,
			&game->mlx.img.endian);
	ft_updating(game);
	ft_drawing(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr,
		game->mlx.win_ptr,
		game->mlx.img.img_ptr,
		0,
		0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
	return (1);
}

int	ft_launch_game(t_game *game, t_map *ma_map)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (EXIT_FAILURE);
	mlx_get_screen_size(game->mlx.mlx_ptr, &game->disp.reso.width,
		&game->disp.reso.height);
	game->disp.reso.width = 1280;
	game->disp.reso.height = 720;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			game->disp.reso.width, game->disp.reso.height, "Cub3d");
	if (!game->mlx.win_ptr)
		return (EXIT_FAILURE);
	ft_game_init(game, ma_map); // ICI
	mlx_loop_hook(game->mlx.mlx_ptr, ft_next_frame, game);
	mlx_loop(game->mlx.mlx_ptr);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_display(game->mlx.mlx_ptr);
	return (0);
}
