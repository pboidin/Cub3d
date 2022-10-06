/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:09:13 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 14:56:25 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_final_check(t_map *ma_map, char **map)
{
	if (ma_map->start_pos != 1)
	{
		printf("Error: missing starting position\n");
		ft_exit(ma_map, map);
	}
	if (*ma_map->ea_path == '\n' || *ma_map->no_path == '\n'
		|| *ma_map->so_path == '\n' || *ma_map->we_path == '\n')
	{
		printf("Error: empty path\n");
		ft_exit (ma_map, map);
	}
	return (0);
}

int	ft_check_inside_first_line(t_map *ma_map, char **map, int i, int *count)
{
	(*count)++;
	if (ft_check_first_line(map[i]) == -1)
	{
		printf("Error: bad element in first line\n");
		ft_exit(ma_map, map);
	}
	if (ft_check_next_line(map[i + 1]) == -1)
	{
		printf("Error: next line is empty\n");
		ft_exit(ma_map, map);
	}
	return (0);
}

int	ft_check_inside_line(t_map *ma_map, char **map, int i, int j)
{
	if (ft_check_inside_map(ma_map, map[i]) == -1)
	{
		printf("Error: forbidden element in map\n");
		ft_exit(ma_map, map);
	}
	else if (ft_last_character(map[i]) == -1)
	{	
		printf("Error: last char is not '1'\n");
		ft_exit(ma_map, map);
	}
	else if (ft_check_zero(map[i - 1], map[i + 1], map[i], j) == -1)
	{	
		printf("Error: bad zero\n");
		ft_exit(ma_map, map);
	}
	else if (ft_check_next_line(map[i + 1]) == -1)
	{
		printf("Error: next line is empty\n");
		ft_exit(ma_map, map);
	}
	return (0);
}

char	**ft_first_check(t_map *ma_map, char **av)
{
	char	**map;

	map = ft_parse_map(av);
	if (map == NULL)
		return (printf("Error: malloc.\n"), NULL);
	if (ft_parse_rgb(ma_map, av) == -1)
		return (ft_free(map), NULL);
	if (ft_check_last_line(map[ft_open_file(av) - 1]) == -1)
		return (ft_free(map), printf("Error: bad element in last line\n"), NULL);
	return (map);
}

int	ft_check_map(t_map *ma_map, char **av)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	i = -1;
	count = 0;
	map = ft_first_check(ma_map, av);
	if (!map)
		return (-1);
	while (++i < ft_open_file(av) - 1)
	{
		j = 0;
		ft_skip_space(map[i], &j);
		if (map[i][j] == '1' && count == 0)
			ft_check_inside_first_line(ma_map, map, i, &count);
		else if (map[i][j] == '1')
			ft_check_inside_line(ma_map, map, i, j);
		else if (ft_first_char(map[i]) == -1)
			return (ft_free(map), printf("Error: bad first char\n"), -1);
	}
	return (ft_final_check(ma_map, map), ft_free(map), 0);
}
