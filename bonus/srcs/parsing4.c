/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:21:45 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 17:41:07 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_no_so(t_map *ma_map, char **map, int i, int j)
{
	if (map[i][j] == 'N' && map[i][j + 1] == 'O'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
	{
		j = j + 2;
		ft_skip_space2(map[i], &j);
		if (ma_map->no_path == NULL)
			ma_map->no_path = ft_strdup(map[i] + j);
		ma_map->c_no++;
	}
	if (map[i][j] == 'S' && map[i][j + 1] == 'O'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
	{
		j = j + 2;
		ft_skip_space2(map[i], &j);
		if (ma_map->so_path == NULL)
			ma_map->so_path = ft_strdup(map[i] + j);
		ma_map->c_so++;
	}
}

void	ft_ea_we(t_map *ma_map, char **map, int i, int j)
{
	if (map[i][j] == 'W' && map[i][j + 1] == 'E'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
	{
		j = j + 2;
		ft_skip_space2(map[i], &j);
		if (ma_map->we_path == NULL)
			ma_map->we_path = ft_strdup(map[i] + j);
		ma_map->c_we++;
	}
	if (map[i][j] == 'E' && map[i][j + 1] == 'A'
		&& (map[i][j + 2] == ' ' || map[i][j + 2] == '\t'))
	{
		j = j + 2;
		ft_skip_space2(map[i], &j);
		if (ma_map->ea_path == NULL)
			ma_map->ea_path = ft_strdup(map[i] + j);
		ma_map->c_ea++;
	}
}

int	ft_parse_dup_text(t_map *ma_map, char **av)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = ft_parse_map(av);
	if (map == NULL)
		return (printf("Error: malloc.\n"), -1);
	ft_init_count_text(ma_map);
	while (++i < ft_open_file(av))
	{
		j = 0;
		ft_skip_space2(map[i], &j);
		ft_no_so(ma_map, map, i, j);
		ft_ea_we(ma_map, map, i, j);
	}
	if (ma_map->c_no != 1 || ma_map->c_so != 1
		|| ma_map->c_ea != 1 || ma_map->c_we != 1)
		return (ft_free(map), printf("Error: texture\n"), -1);
	return (ft_free(map), 0);
}

int	ft_parse_dup_rgb(char **av)
{
	int		i;
	int		j;
	int		count_c;
	int		count_f;
	char	**map;

	i = -1;
	count_c = 0;
	count_f = 0;
	map = ft_parse_map(av);
	if (map == NULL)
		return (printf("Error: malloc.\n"), -1);
	while (++i < ft_open_file(av))
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == 'F')
			count_f++;
		if (map[i][j] == 'C')
			count_c++;
	}
	if (count_c != 1 || count_f != 1)
		return (ft_free(map), printf("Error: rgb.\n"), -1);
	return (ft_free(map), 0);
}

int	ft_first_step_rgb(t_map *ma_map, char **av)
{
	if (ft_parse_dup_rgb(av) == -1
		|| ft_parse_dup_text(ma_map, av) == -1)
		return (-1);
	if (ft_init_rgb(ma_map) != 0)
		return (ft_free_path(ma_map), printf("Error: malloc.\n"), -1);
	if (ft_is_rgb(ma_map, av) == -1)
		return (ft_free_color(ma_map), ft_free_path(ma_map),
			printf("Error: malloc.\n"), -1);
	if (ft_verif_floor(ma_map) == -1 || ft_verif_ceiling(ma_map) == -1)
		return (-1);
	ft_floor(ma_map);
	ft_ceiling(ma_map);
	return (0);
}
