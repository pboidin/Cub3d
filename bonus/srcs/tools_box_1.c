/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_box_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:28:22 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 15:11:21 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_map(t_mapi *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		free(map->map[i]);
	}
	free(map->map);
}

void	ft_free_disp(t_disp *disp)
{
	free(disp->no_tex.path);
	free(disp->so_tex.path);
	free(disp->we_tex.path);
	free(disp->ea_tex.path);
	free_map(&disp->map);
}

void	ft_free_game(t_game *game)
{
	ft_free_disp(&game->disp);
	free(game->rays.arr);
}

double	deg_transform(double deg)
{
	return (deg * M_PI / 180.0);
}

double	ft_radian_norm(double rad)
{
	double	circle;

	circle = deg_transform(360);
	rad = fmod(rad, circle);
	if (rad < 0)
		rad += circle;
	return (rad);
}
