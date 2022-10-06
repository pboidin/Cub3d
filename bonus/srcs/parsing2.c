/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:20:28 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/05 17:56:10 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_verif_floor(t_map *ma_map)
{
	int	i;

	i = -1;
	while (ma_map->floor[++i])
	{
		if (ma_map->floor[i] != ',' && !(ma_map->floor[i] >= '0'
				&& ma_map->floor[i] <= '9') && ma_map->floor[i] != '\0'
			&& ma_map->floor[i] != '\n')
			return (printf("Error: invalid element rgb floor\n"), -1);
	}
	return (0);
}


void	ft_inside_floor(t_map *ma_map, int i, int j)
{
	while (ma_map->floor[i] && ma_map->floor[i] != ',')
		ma_map->f_r[j++] = ma_map->floor[i++];
	ma_map->f_r[j] = '\0';
	if (ma_map->floor[i])
		i++;
	j = 0;
	while (ma_map->floor[i] && ma_map->floor[i] != ',')
		ma_map->f_g[j++] = ma_map->floor[i++];
	ma_map->f_g[j] = '\0';
	if (ma_map->floor[i])
		i++;
	j = 0;
	while (ma_map->floor[i] && ma_map->floor[i] != '\n')
		ma_map->f_b[j++] = ma_map->floor[i++];
	ma_map->f_b[j] = '\0';
}


int	ft_floor(t_map *ma_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_inside_floor(ma_map, i, j);
	return (1);
}

void	ft_inside_ceiling(t_map *ma_map, int i, int j)
{
	while (ma_map->ceiling[i] && ma_map->ceiling[i] != ',')
		ma_map->c_r[j++] = ma_map->ceiling[i++];
	ma_map->c_r[j] = '\0';
	if (ma_map->ceiling[i])
		i++;
	j = 0;
	while (ma_map->ceiling[i] && ma_map->ceiling[i] != ',')
		ma_map->c_g[j++] = ma_map->ceiling[i++];
	ma_map->c_g[j] = '\0';
	if (ma_map->ceiling[i])
		i++;
	j = 0;
	while (ma_map->ceiling[i] && ma_map->ceiling[i] != '\n')
		ma_map->c_b[j++] = ma_map->ceiling[i++];
	ma_map->c_b[j] = '\0';
}

int	ft_ceiling(t_map *ma_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_inside_ceiling(ma_map, i, j);
	return (1);
}
