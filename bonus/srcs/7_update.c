/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_update.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:52:42 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 16:41:36 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_upd_rays(t_game *game)
{
	double	angle_ray;
	int		i;

	angle_ray = game->player.rot_ang - game->rays.angle_view / 2;
	i = -1;
	while (++i < game->disp.reso.width)
	{
		game->rays.arr[i].angle = angle_ray;
		ft_raycast(&game->rays.arr[i], &game->disp.map, &game->player);
		angle_ray += game->rays.angle_view / game->disp.reso.width;
	}
}

void	ft_upd_player_ori(t_player *player)
{
	double	rot;

	if (player->turn_dir == 0)
		return ;
	rot = player->turn_dir * player->rot_speed;
	player->rot_ang += rot;
}

void	ft_upd_player_pos(char **grid, t_player *player)
{
	double	rot;
	double	move;

	if (player->walk_dir == 0)
		return ;
	move = player->speed;
	rot = player->rot_ang;
	if (player->walk_dir == 's')
		move = (-1) * player->speed;
	else if (player->walk_dir == 'a')
	{
		move = (-1) * player->speed;
		rot = player->rot_ang + deg_transform(90);
	}
	else if (player->walk_dir == 'd')
		rot = player->rot_ang + deg_transform(90);
	player->x += cos(rot) * move;
	player->y += sin(rot) * move;
	if (ft_strchr("1", grid[(int)player->y][(int)player->x]))
	{
		player->x -= cos(rot) * move;
		player->y -= sin(rot) * move;
	}
}

void	ft_updating(t_game *game)
{
	ft_upd_player_pos(game->disp.map.map, &game->player);
	ft_upd_player_ori(&game->player);
	ft_upd_rays(game);
}
