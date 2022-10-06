/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:43:45 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 15:11:21 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_load_text(void *mlx, t_text *texture)
{
	texture->img_tex.img_ptr = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->width, &texture->height);
	texture->img_tex.data = (int *)mlx_get_data_addr(texture->img_tex.img_ptr,
			&texture->img_tex.bpp, &texture->img_tex.size_l,
			&texture->img_tex.endian);
}

void	ft_set_rays(t_game *game)
{
	game->rays.arr = malloc(sizeof(t_ray) * game->disp.reso.width);
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->rays.angle_view = deg_transform(VIEW_ANGLE);
	game->rays.dist_proj = (game->disp.reso.width / 2)
		/ tan(game->rays.angle_view / 2);
}

void	ft_init_game(t_game *game)
{
	game->disp.mini_map = game->disp.reso.width / 200; // BONUS
	ft_set_rays(game);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.no_tex);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.so_tex);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.we_tex);
	ft_load_text(game->mlx.mlx_ptr, &game->disp.ea_tex);
}
