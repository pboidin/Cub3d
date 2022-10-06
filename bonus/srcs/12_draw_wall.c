/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:53:27 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 15:11:21 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_text	ft_get_wall_tex(t_disp *disp, char orienta)
{
	if (orienta == 'N')
		return (disp->no_tex);
	else if (orienta == 'S')
		return (disp->so_tex);
	else if (orienta == 'W')
		return (disp->we_tex);
	else
		return (disp->ea_tex);
}

int	ft_get_y_wall_pos(t_game *game, double wall_hei)
{
	double	screen_cent;
	double	wall_cent;
	int		y;

	screen_cent = game->disp.reso.height / 2;
	wall_cent = wall_hei / 2;
	y = screen_cent - wall_cent;
	if (y < 0)
		y = 0;
	return (y);
}

double	ft_get_hei_wall(t_game *game, t_ray *ray)
{
	double	wall_hei;
	double	scal_dis;
	double	adju_fish;

	adju_fish = cos(ray->angle - game->player.rot_ang);
	scal_dis = ray->size * SCALE * adju_fish;
	wall_hei = (SCALE / (scal_dis)) * game->rays.dist_proj;
	return (wall_hei);
}

void	ft_draw_wall(t_game *game)
{
	int		i;
	double	wall_hei;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->disp.reso.width)
	{
		ray = &game->rays.arr[i];
		wall_hei = ft_get_hei_wall(game, ray);
		rect.x = i;
		rect.y = ft_get_y_wall_pos(game, wall_hei);
		rect.hei = wall_hei;
		rect.tex = ft_get_wall_tex(&game->disp, ray->orienta);
		ft_draw_strip_w(&rect, game->mlx.img.data, &game->disp.reso, ray);
	}
}
