#include "../includes/cub.h"

int		ft_south(double angle)
{
	if (0 <= angle && angle < M_PI)
		return (1);
	else
		return (0);
}

char	ft_get_wall_orient(t_map *map, int x, int y, t_ray *ray) // Obtient l'orientation d'un mur. Si nous avons trouvé ce mur, cela signifie qu'il y a au moins un espace sans mur à côté de lui. Nous prenons également en compte le bord de la grille (hrzn ou vrtl) qui a été touché et l'angle du rayon touchant le mur
{
	if (x == 0)
		return ('E');
	else if (x == map->width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->height - 1)
		return ('N');
	if (ray->side == 'H')
	{
		if (map->map[y - 1][x] != '1' && ft_south(ray->angle))
			return ('N');
		else if (map->map[y + 1][x] != '1' && !ft_south(ray->angle))
			return ('S');
	}
	else
	{
		if (map->map[y][x - 1] != '1' && !ft_west(ray->angle))
			return ('W');
		else if (map->map[y][x + 1] != '1' && ft_west(ray->angle))
			return ('E');
	}
	return (0);
}

int		ft_wall(t_map *map, double x, double y, t_ray *ray) // Chaque fois qu'une intersection de grille (x == 0 ou y == 0) est trouvée, cette fonction vérifie si c'est un mur
{
	ray->x = x;
	ray->y = y;
	if ((int)x < 0 || map->width < (int)x || (int)y < 0 || map->height < (int)y) // Limite : le rayon est sorti des limites de la grille. Nous arrêtons le rayon et lui donnons une valeur très élevée pour qu'il ne soit pas choisi comme le plus proche du joueur.
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (map->height == (int)y) // Limite : le rayon s'est retrouvé juste sur le bord sud de la grille. Comme la grille est un tableau de chaînes de caractères à terminaison NULL, si on vérifie une valeur x de cette ligne, on seg.
	{
		ray->obst = '1';
		ray->orienta = 'N';
		return (1);
	}
	ray->obst = map->map[(int)y][(int)x];
	if (ray->obst == '1')
	{
		ray->orienta = ft_get_wall_orient(map, (int)x, (int)y, ray);
		return (1);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
}

void	ft_draw_rect(t_rect *rect, int *img, int reso_wid) // Dessine un rectangle dans la mlx_image
{
	int	i;
	int	j;
	int	x_tmp;
	int	y_tmp;

	rect->bord_wid--;
	i = -1;
	while (++i < rect->hei)
	{
		j = -1;
		while (++j < rect->wid)
		{
			x_tmp = rect->x + j;
			y_tmp = rect->y + i;
			if (i <= rect->bord_wid || j <= rect->bord_wid
				|| i >= rect->hei - 1 - rect->bord_wid
				|| j >= rect->wid - 1 - rect->bord_wid)
				img[y_tmp * reso_wid + x_tmp] = rect->bord_col;
			else
				img[y_tmp * reso_wid + x_tmp] = rect->fill_col;
		}
	}
}