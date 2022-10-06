/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_raycast_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:53:18 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:43:39 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_get_v_inter_ea(t_ray *ray, t_mapi *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	x = ceil(player->x);
	x_tmp = x - player->x;
	y_tmp = x_tmp * tan(ray->angle);
	y = player->y + y_tmp;
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x, y, ray))
		return ;
	x_tmp = 1;
	y_tmp = x_tmp * tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x, y, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_v_inter_we(t_ray *ray, t_mapi *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	x = floor(player->x);
	x_tmp = player->x - x;
	y_tmp = x_tmp * tan(ray->angle);
	y = player->y - y_tmp;
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x - 1, y, ray))
		return ;
	x_tmp = -1;
	y_tmp = x_tmp * tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x - 1, y, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_v_inter(t_ray *ray, t_mapi *map, t_player *player)
{
	ray->size = 0;
	if (ray->angle == deg_transform(90) || ray->angle == deg_transform(270))
	{
		ray->size = INT_MAX;
		return ;
	}
	if (ft_west(ray->angle))
		ft_get_v_inter_we(ray, map, player);
	else
		ft_get_v_inter_ea(ray, map, player);
}
