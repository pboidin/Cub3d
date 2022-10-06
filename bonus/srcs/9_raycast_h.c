/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_raycast_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:53:13 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:43:14 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_get_h_inter_no(t_ray *ray, t_mapi *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	y = floor(player->y);
	y_tmp = player->y - y;
	x_tmp = y_tmp / tan(ray->angle);
	x = player->x - x_tmp;
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x, y - 1, ray))
		return ;
	y_tmp = -1;
	x_tmp = +y_tmp / tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x, y - 1, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_h_inter_so(t_ray *ray, t_mapi *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	y = ceil(player->y);
	y_tmp = y - player->y;
	x_tmp = y_tmp / tan(ray->angle);
	x = player->x + x_tmp;
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x, y, ray))
		return ;
	y_tmp = 1;
	x_tmp = y_tmp / tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x, y, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_h_inter(t_ray *ray, t_mapi *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_transform(180) || ray->angle == deg_transform(360))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (ft_south(ray->angle))
		ft_get_h_inter_so(ray, map, player);
	else
		ft_get_h_inter_no(ray, map, player);
}
