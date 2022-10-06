/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_box_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:28:42 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 14:35:45 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_west(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (1)
	{
		if (*s1 != *s2++)
		{
			--s2;
			if (*s1 < 0 || *s2 < 0)
				return ((unsigned char)(*s1 - *s2));
			return (*s1 - *s2);
		}
		if (*s1++ == 0)
			break ;
		if (--n == 0)
			break ;
	}
	return (0);
}

void	free_str(char **str)
{
	while (*str)
		free(*str++);
}

int	ft_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (-1);
}

void	ft_init_null(t_map *ma_map)
{
	ma_map->map = NULL;
	ma_map->floor = NULL;
	ma_map->ceiling = NULL;
	ma_map->no_path = NULL;
	ma_map->so_path = NULL;
	ma_map->ea_path = NULL;
	ma_map->we_path = NULL;
	ma_map->f_r = NULL;
	ma_map->f_g = NULL;
	ma_map->f_b = NULL;
	ma_map->c_r = NULL;
	ma_map->c_g = NULL;
	ma_map->c_b = NULL;
}
