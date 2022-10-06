/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:30:44 by madelaha          #+#    #+#             */
/*   Updated: 2022/09/30 14:13:43 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_concat(char *str, char *buffer)
{
	int		i;
	int		j;
	int		n;
	char	*dstf;

	i = 0;
	j = ft_strlen(str) + ft_strlen(buffer);
	if (!j)
		return (free(str), NULL);
	dstf = malloc(sizeof(char) * (j + 1));
	if (!dstf)
		return (NULL);
	while (str && str[i])
	{
		dstf[i] = str[i];
		i++;
	}
	n = 0;
	while (i < j)
		dstf[i++] = buffer[n++];
	dstf[i] = '\0';
	free(str);
	return (dstf);
}

char	*ft_get_line(char *str)
{
	int		i;
	int		j;
	char	*dstf;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_check(str, '\n');
	if (j == -1)
		j = ft_strlen(str) - 1;
	dstf = malloc(sizeof(char) * (j + 2));
	if (!dstf)
		return (NULL);
	while (i <= j)
	{
		dstf[i] = str[i];
		i++;
	}
	dstf[i] = '\0';
	return (dstf);
}

char	*ft_get_next(char *str, char *line)
{
	int		i;
	int		j;
	int		n;
	char	*dstf;

	i = 0;
	j = ft_strlen(line);
	n = ft_strlen(str) - j;
	if (!n)
		return (free(str), NULL);
	dstf = malloc(sizeof(char) * (n + 1));
	if (!dstf)
		return (NULL);
	while (i < n)
	{
		dstf[i] = str[j + i];
		i++;
	}
	dstf[i] = '\0';
	free(str);
	return (dstf);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*str = NULL;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		str = ft_concat(str, buff);
		if (ft_check(str, '\n') > -1)
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	line = ft_get_line(str);
	str = ft_get_next(str, line);
	return (free(buff), line);
}
