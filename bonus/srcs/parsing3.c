/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:21:13 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 14:59:42 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_is_rgb(t_map *ma_map, char **av)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = ft_parse_map(av);
	if (map == NULL)
		return (-1);
	while (++i < ft_open_file(av))
	{
		j = 0;
		ft_skip_space(map[i], &j);
		ft_is_rgb2(ma_map, map, i, j);
	}
	if (ma_map->ceiling == NULL || ma_map->floor == NULL)
		return (ft_free(map), -1);
	return (ft_free(map), 0);
}

int	ft_check_floor(t_map *ma_map)
{
	if (*ma_map->f_r == '\n' || *ma_map->f_g == '\n' || *ma_map->f_b == '\n')
		return (-1);
	if (*ma_map->f_r == '\0' || *ma_map->f_g == '\0' || *ma_map->f_b == '\0')
		return (-1);
	return (0);
}

int	ft_check_ceiling(t_map *ma_map)
{
	if (*ma_map->c_r == '\n' || *ma_map->c_g == '\n' || *ma_map->c_b == '\n')
		return (-1);
	if (*ma_map->c_r == '\0' || *ma_map->c_g == '\0' || *ma_map->c_b == '\0')
		return (-1);
	return (0);
}

int	ft_check_f(t_map *ma_map)
{
	if (ft_check_floor(ma_map) == -1)
		return (printf("ERROR: invalid rgb floor\n"), -1);
	if (ft_atoi(ma_map->f_r) < 0 || ft_atoi(ma_map->f_r) > 255)
		return (printf("ERROR: invalid rgb floor\n"), -1);
	if (ft_atoi(ma_map->f_g) < 0 || ft_atoi(ma_map->f_g) > 255)
		return (printf("ERROR: invalid rgb floor\n"), -1);
	if (ft_atoi(ma_map->f_b) < 0 || ft_atoi(ma_map->f_b) > 255)
		return (printf("ERROR: invalid rgb floor\n"), -1);
	return (0);
}

int	ft_check_c(t_map *ma_map)
{
	if (ft_check_ceiling(ma_map) == -1)
		return (printf("ERROR: invalid rgb ceiling\n"), -1);
	if (ft_atoi(ma_map->c_r) < 0 || ft_atoi(ma_map->c_r) > 255)
		return (printf("ERROR: invalid rgb ceiling\n"), -1);
	if (ft_atoi(ma_map->c_g) < 0 || ft_atoi(ma_map->c_g) > 255)
		return (printf("ERROR: invalid rgb ceiling\n"), -1);
	if (ft_atoi(ma_map->c_b) < 0 || ft_atoi(ma_map->c_b) > 255)
		return (printf("ERROR: invalid rgb ceiling\n"), -1);
	return (0);
}
