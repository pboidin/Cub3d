/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_box_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:28:52 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/05 18:04:03 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_draw_circle(t_circle *circle, int *img, int reso_wid)
{
	double	angle;
	double	x;
	double	y;
	int		x_tmp;
	int		y_tmp;

	angle = 0;
	while (angle <= 360)
	{
		x = circle->rad * cos(deg_transform(angle));
		y = circle->rad * sin(deg_transform(angle));
		x_tmp = circle->x + (int)x;
		y_tmp = circle->y + (int)y;
		img[y_tmp * reso_wid + x_tmp] = circle->col;
		angle += 0.1;
	}
}

void	ft_draw_line(t_line *line, int *img, int reso_wid)
{
	double	x_diff;
	double	y_diff;
	int		pix;
	double	x_pix;
	double	y_pix;

	x_diff = line->end_x - line->beg_x;
	y_diff = line->end_y - line->beg_y;
	pix = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
	x_diff /= pix;
	y_diff /= pix;
	x_pix = line->beg_x;
	y_pix = line->beg_y;
	while (pix)
	{
		img[(int)y_pix * reso_wid + (int)x_pix] = line->col;
		x_pix += x_diff;
		y_pix += y_diff;
		pix--;
	}
}

void	ft_free_path(t_map *ma_map)
{
	free(ma_map->no_path);
	free(ma_map->so_path);
	free(ma_map->ea_path);
	free(ma_map->we_path);
}

void	ft_skip_space(char *str, int *j)
{
	while (str[*j] == ' ' || str[*j] == '\t')
	{
		(*j)++;
	}
}

int	ft_exit(t_map *ma_map, char **map)
{
	ft_free_rgb(ma_map);
	ft_free(map);
	exit (-1);
}
