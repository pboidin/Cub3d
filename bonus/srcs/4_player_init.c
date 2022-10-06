/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:43:01 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:37:41 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

double	ft_start_orient(char orient)
{
	double	rad;

	rad = 0;
	if (orient == 'N')
		rad = deg_transform(270);
	else if (orient == 'S')
		rad = deg_transform(90);
	else if (orient == 'W')
		rad = deg_transform(180);
	else if (orient == 'E')
		rad = deg_transform(360);
	return (rad);
}

void	ft_start_position(char **map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				player->rot_ang = ft_start_orient(map[i][j]);
				map[i][j] = '0';
			}
		}	
	}
}

void	ft_init_player(t_game *game)
{
	game->player.walk_dir = 0;
	game->player.speed = 0.15;
	game->player.turn_dir = 0;
	game->player.rot_speed = deg_transform(4);
	ft_start_position(game->disp.map.map, &game->player);
}
