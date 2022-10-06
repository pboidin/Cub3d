/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:20:17 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 14:59:55 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

void	ft_free_color(t_map *ma_map)
{
	free(ma_map->f_r);
	free(ma_map->f_g);
	free(ma_map->f_b);
	free(ma_map->c_r);
	free(ma_map->c_g);
	free(ma_map->c_b);
}

void	ft_free_rgb(t_map *ma_map)
{
	if (ma_map->floor)
		free(ma_map->floor);
	if (ma_map->ceiling)
		free(ma_map->ceiling);
	if (ma_map->f_r)
		free(ma_map->f_r);
	if (ma_map->f_g)
		free(ma_map->f_g);
	if (ma_map->f_b)
		free(ma_map->f_b);
	if (ma_map->c_r)
		free(ma_map->c_r);
	if (ma_map->c_g)
		free(ma_map->c_g);
	if (ma_map->c_b)
		free(ma_map->c_b);
	if (ma_map->so_path)
		free(ma_map->so_path);
	if (ma_map->no_path)
		free(ma_map->no_path);
	if (ma_map->we_path)
		free(ma_map->we_path);
	if (ma_map->ea_path)
		free(ma_map->ea_path);
}

void	ft_is_rgb2(t_map *ma_map, char **map, int i, int j)
{
	if (map[i][j] == 'F' && map[i][j + 1] == ' ')
	{
		j = j + 2;
		ft_skip_space(map[i], &j);
		ma_map->floor = ft_strdup(map[i] + j);
	}
	if (map[i][j] == 'C' && map[i][j + 1] == ' ')
	{
		j = j + 2;
		ft_skip_space(map[i], &j);
		ma_map->ceiling = ft_strdup(map[i] + j);
	}
}
