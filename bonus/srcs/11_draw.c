/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:53:23 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:44:13 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_draw_ceilling(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.wid = game->disp.reso.width;
	rect.hei = game->disp.reso.height / 2;
	rect.bord_wid = 0;
	rect.fill_col = game->disp.ceilling.argb;
	ft_draw_rect(&rect, game->mlx.img.data, game->disp.reso.width);
}

void	ft_draw_floor(t_game *game)
{
	t_rect	rect;

	rect.x = 0;
	rect.y = game->disp.reso.height / 2;
	rect.wid = game->disp.reso.width;
	rect.hei = game->disp.reso.height / 2;
	rect.bord_wid = 0;
	rect.fill_col = game->disp.floor.argb;
	ft_draw_rect(&rect, game->mlx.img.data, game->disp.reso.width);
}

void	ft_drawing(t_game *game)
{
	ft_draw_ceilling(game);
	ft_draw_floor(game);
	ft_draw_wall(game);
	ft_draw_mini_map(game);
}
