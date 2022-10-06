/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:04:56 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 14:36:14 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_first_init(char **av)
{
	if (ft_name_file(av) == FALSE)
		return (printf("Error: invalid name of file\n"), -1);
	else if (ft_open_file(av) == FALSE)
		return (printf("Error: invalid file\n"), -1);
	return (0);
}

void	ft_init_count_text(t_map *ma_map)
{
	ma_map->c_no = 0;
	ma_map->c_so = 0;
	ma_map->c_we = 0;
	ma_map->c_ea = 0;
	ma_map->start_pos = 0;
	ma_map->x_player = 0;
	ma_map->y_player = 0;
}

int	ft_init_rgb(t_map *ma_map)
{
	ma_map->f_r = malloc(sizeof(char) * 5);
	if (!ma_map->f_r)
		return (-1);
	ma_map->f_g = malloc(sizeof(char) * 5);
	if (!ma_map->f_g)
		return (free(ma_map->f_r), -2);
	ma_map->f_b = malloc(sizeof(char) * 5);
	if (!ma_map->f_b)
		return (free(ma_map->f_r), free(ma_map->f_g), -3);
	ma_map->c_r = malloc(sizeof(char) * 5);
	if (!ma_map->c_r)
		return (free(ma_map->f_r), free(ma_map->f_g), free(ma_map->f_b), -4);
	ma_map->c_g = malloc(sizeof(char) * 5);
	if (!ma_map->c_g)
		return (free(ma_map->f_r), free(ma_map->f_g),
			free(ma_map->f_b), free(ma_map->c_r), -5);
	ma_map->c_b = malloc(sizeof(char) * 5);
	if (!ma_map->c_b)
		return (free(ma_map->f_r), free(ma_map->f_g), free(ma_map->f_b),
			free(ma_map->c_r), free(ma_map->c_g), -6);
	return (0);
}

char	**ft_recup_map(char **av)
{
	int		i;
	int		j;
	char	**map;
	char	**map_final;

	i = -1;
	map = ft_parse_map(av);
	map_final = malloc(sizeof(char *) * (ft_open_file(av) + 1));
	if (!map_final)
		return (ft_free(map), NULL);
	while (map[++i])
	{
		j = 0;
		ft_skip_space(map[i], &j);
		if (map[i][j] == '1')
			break ;
	}
	j = -1;
	while (map[i])
	{
		map_final[++j] = ft_strdup2(map[i]);
		i++;
	}
	map_final[++j] = NULL;
	return (ft_free(map), map_final);
}

int	main(int ac, char **av)
{
	t_map	ma_map;
	t_game	game;

	if (ac != 2)
		return (printf("Error: too many or not enough arg\n"), -1);
	if (ft_first_init(av) == -1)
		return (-1);
	ft_init_null(&ma_map);
	if (ft_check_map(&ma_map, av) == -1)
		return (ft_free_rgb(&ma_map), -1);
	ma_map.map = ft_recup_map(av);
	if (ma_map.map == NULL)
		return (ft_free_rgb(&ma_map), printf("Error: malloc\n"), -1);
	ft_init_struct(&ma_map, &game.disp);
	ft_launch_game(&game, &ma_map);
	ft_free_rgb(&ma_map);
	ft_free(ma_map.map);
	return (0);
}
