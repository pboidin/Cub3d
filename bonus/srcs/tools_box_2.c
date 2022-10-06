/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_box_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:28:34 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 12:54:33 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_south(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

char	ft_get_wall_orient(t_mapi *map, int x, int y, t_ray *ray)
{
	if (x == 0)
		return ('E');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (ray->side == 'H')
	{
		if (map->map[y - 1][x] != '1' && ft_south(ray->angle))
			return ('N');
		else if (map->map[y + 1][x] != '1' && !ft_south(ray->angle))
			return ('S');
	}
	else
	{
		if (map->map[y][x - 1] != '1' && !ft_west(ray->angle))
			return ('W');
		else if (map->map[y][x + 1] != '1' && ft_west(ray->angle))
			return ('E');
	}
	return (0);
}

int	ft_wall(t_mapi *map, double x, double y, t_ray *ray)
{
	ray->x = x;
	ray->y = y;
	if ((int)x < 0 || map->width < (int)x || (int)y < 0 || map->height < (int)y)
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (map->height == (int)y)
	{
		ray->obst = '1';
		ray->orienta = 'N';
		return (1);
	}
	ray->obst = map->map[(int)y][(int)x];
	if (ray->obst == '1')
	{
		ray->orienta = ft_get_wall_orient(map, (int)x, (int)y, ray);
		return (1);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
}

void	ft_draw_rect(t_rect *rect, int *img, int reso_wid)
{
	int	i;
	int	j;
	int	x_tmp;
	int	y_tmp;

	rect->bord_wid--;
	i = -1;
	while (++i < rect->hei)
	{
		j = -1;
		while (++j < rect->wid)
		{
			x_tmp = rect->x + j;
			y_tmp = rect->y + i;
			if (i <= rect->bord_wid || j <= rect->bord_wid
				|| i >= rect->hei - 1 - rect->bord_wid
				|| j >= rect->wid - 1 - rect->bord_wid)
				img[y_tmp * reso_wid + x_tmp] = rect->bord_col;
			else
				img[y_tmp * reso_wid + x_tmp] = rect->fill_col;
		}
	}
}
