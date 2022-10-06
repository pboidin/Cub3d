/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_game_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:42:16 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/27 18:07:07 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_game_init(t_game *game, t_map *ma_map)
{
	ft_init_player(game);
	ft_init_events(game, ma_map); // ICI
	ft_init_game(game);
}
