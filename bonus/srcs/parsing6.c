/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:22:43 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/05 17:57:27 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_z_or_o(char c)
{
	if (c == '0' || c == '1')
		return (0);
	return (-1);
}

int	ft_first_char(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'C' || str[i] == 'F' || str[i] == '1' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\0'
		|| (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		|| (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		|| (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		|| (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		|| str[i] == '\t')
		return (0);
	return (-1);
}

int	ft_check_zero(char *line_up, char *line_do, char *line, int j)
{
	while (line[j] && line_do[j])
	{
		if (line[j] == '0')
		{
			if (line_do[j] && ft_z_or_o(line_do[j]) == -1
				&& ft_pos(line_do[j]) == -1)
				return (-1);
			else if (ft_z_or_o(line_up[j]) == -1 && ft_pos(line_up[j]) == -1)
				return (-1);
			else if (ft_z_or_o(line[j - 1]) == -1 && ft_pos(line[j - 1]) == -1)
				return (-1);
			else if (ft_z_or_o(line[j + 1]) == -1 && ft_pos(line[j + 1]) == -1)
				return (-1);
		}
		j++;
	}
	return (0);
}

int	ft_last_character(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i = i - 2;
	if (str[i] != '1')
		return (-1);
	return (0);
}

int	ft_check_next_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (-1);
	return (0);
}
