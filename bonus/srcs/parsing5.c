/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:22:20 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/05 17:57:05 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_parse_rgb2(t_map *ma_map, char **map, int i, int j)
{
	if (map[i][j] == 'C')
	{
		if (ft_check_c(ma_map) == -1)
			return (ft_free(map), -1);
	}
	if (map[i][j] == 'F')
	{
		if (ft_check_f(ma_map) == -1)
			return (ft_free(map), -1);
	}
	return (0);
}

int	ft_parse_rgb(t_map *ma_map, char **av)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = ft_parse_map(av);
	if (map == NULL)
		return (-1);
	if (ft_first_step_rgb(ma_map, av) == -1)
		return (ft_free(map), -1);
	while (++i < ft_open_file(av))
	{
		j = 0;
		ft_skip_space(map[i], &j);
		if (ft_parse_rgb2(ma_map, map, i, j) == -1)
			return (-1);
	}
	return (ft_free(map), 0);
}

int	ft_check_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_last_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_inside_map(t_map *ma_map, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ma_map->start_pos > 1)
			return (printf("Error: too many start position\n"), -1);
		if (str[i] != '1' && str[i] != '0' && str[i] != ' '
			&& (ft_pos(str[i]) == -1) && str[i] != '\n' && str[i] != '\t')
			return (-1);
		if (ft_pos(str[i]) == 0)
			ma_map->start_pos++;
		i++;
	}
	return (0);
}
