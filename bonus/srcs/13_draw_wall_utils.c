/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_draw_wall_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:53:30 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:46:18 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_bit_mapper(t_ray *ray, int bitmap_wi)
{
	double	re;
	int		offset;

	if (ray->side == 'H')
	{
		re = ray->x - floor(ray->x);
		offset = bitmap_wi * re;
	}
	else
	{
		re = ray->y - floor(ray->y);
		offset = bitmap_wi * re;
	}
	return (offset);
}

void	ft_draw_strip_w(t_rect *rect, int *img, t_reso *reso, t_ray *ray)
{
	int		y;
	int		x_text;
	int		y_text;
	double	tmp;
	double	tex;

	tmp = 1.0 * rect->tex.height / rect->hei;
	tex = (rect->y - reso->height / 2 + rect->hei / 2) * tmp;
	x_text = ft_bit_mapper(ray, rect->tex.width);
	y = -1;
	while (++y < rect->hei && y < reso->height)
	{
		y_text = (int)tex & (rect->tex.height - 1);
		tex += tmp;
		img[(rect->y * reso->width) + (y * reso->width)
			+ rect->x] = rect->tex.img_tex.data[y_text
			* rect->tex.height + x_text];
	}
}
