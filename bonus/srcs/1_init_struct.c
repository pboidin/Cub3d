/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:25:32 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 15:11:21 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	check_extension(char *file, char *extension)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(extension);
	if (len_file <= len_ext)
		return (0);
	else if (!ft_strncmp(&file[len_file - len_ext], extension, len_ext + 1))
		return (1);
	else
		return (0);
}

int	ft_check_texture(t_map *ma_map, char *path, char *name)
{
	int	fd;

	if (path == 0)
	{
		printf("Error: The %s is either missing or poorly "
			"formatted.\n", name);
		ft_exit(ma_map, ma_map->map);
	}
	if (!check_extension(path, ".xpm"))
	{
		printf("Error: File %s doesn't have xpm extension.\n", name);
		ft_exit(ma_map, ma_map->map);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open the %s: ""%s\n", name, path);
		ft_exit(ma_map, ma_map->map);
	}
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file %s.\n", path);
		ft_exit(ma_map, ma_map->map);
	}
	return (0);
}

void	ft_check_texture2(t_map *ma_map, t_disp *disp)
{
	ft_check_texture(ma_map, disp->no_tex.path, "north texture");
	ft_check_texture(ma_map, disp->so_tex.path, "south texture");
	ft_check_texture(ma_map, disp->we_tex.path, "west texture");
	ft_check_texture(ma_map, disp->ea_tex.path, "east texture");
}

void	ft_init_struct(t_map *ma_map, t_disp *disp)
{
	disp->map.map = ma_map->map;
	disp->map.width = ft_save_width(disp->map.map);
	disp->map.height = ft_save_height(disp->map.map);
	disp->no_tex.path = ma_map->no_path;
	disp->so_tex.path = ma_map->so_path;
	disp->ea_tex.path = ma_map->ea_path;
	disp->we_tex.path = ma_map->we_path;
	ft_check_texture2(ma_map, disp);
	disp->floor.r = ft_atoi(ma_map->f_r);
	disp->floor.g = ft_atoi(ma_map->f_g);
	disp->floor.b = ft_atoi(ma_map->f_b);
	disp->floor.argb = ft_create_argb(0, disp->floor.r,
			disp->floor.g, disp->floor.b);
	disp->ceilling.r = ft_atoi(ma_map->c_r);
	disp->ceilling.g = ft_atoi(ma_map->c_g);
	disp->ceilling.b = ft_atoi(ma_map->c_b);
	disp->ceilling.argb = ft_create_argb(0, disp->ceilling.r,
			disp->ceilling.g, disp->ceilling.b);
}
