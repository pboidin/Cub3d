/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:31:45 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/28 19:14:22 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_name_file(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (i < 5)
		return (FALSE);
	if (av[1][i - 1] == 'b' && av[1][i - 2] == 'u'
		&& av[1][i - 3] == 'c' && av[1][i - 4] == '.')
		return (TRUE);
	return (FALSE);
}

int	ft_open_file(char **av)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (FALSE);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}

char	**ft_parse_map(char **av)
{
	int		fd;
	int		i;
	int		count;
	char	**map;

	count = ft_open_file(av);
	if (count == 0)
		return (ft_putstr_fd("Error: invalid file\n", 1), NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (FALSE);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < count)
		map[i] = get_next_line(fd);
	map[count] = NULL;
	close(fd);
	return (map);
}

int	ft_verif_ceiling(t_map *ma_map)
{
	int	i;

	i = -1;
	while (ma_map->ceiling[++i])
	{
		if (ma_map->ceiling[i] != ',' && !(ma_map->ceiling[i] >= '0'
				&& ma_map->ceiling[i] <= '9') && ma_map->ceiling[i] != '\0'
			&& ma_map->ceiling[i] != '\n')
			return (printf("Error: invalid element rgb ceiling\n"), -1);
	}
	return (0);
}
