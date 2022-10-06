/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_raycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:53:06 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:42:05 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_raycast(t_ray *ray, t_mapi *map, t_player *player)
{
	t_ray	h_inter;
	t_ray	v_inter;

	h_inter.angle = ft_radian_norm(ray->angle);
	v_inter.angle = ft_radian_norm(ray->angle);
	h_inter.side = 'H';
	v_inter.side = 'V';
	ft_get_h_inter(&h_inter, map, player);
	ft_get_v_inter(&v_inter, map, player);
	if (h_inter.size <= v_inter.size)
		*ray = h_inter;
	else
		*ray = v_inter;
}
