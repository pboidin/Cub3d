#include "cub.h"

void	ft_get_v_inter_ea(t_ray *ray, t_map *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	x = ceil(player->x);
	x_tmp = x - player->x;
	y_tmp = x_tmp * tan(ray->angle);
	y = player->y + y_tmp;
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x, y, ray))
		return ;
	x_tmp = 1;
	y_tmp = x_tmp * tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x, y, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_v_inter_we(t_ray *ray, t_map *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	y = floor(player->y);
	x_tmp = player->x - x; 
	y_tmp = x_tmp * tan(ray->angle);
	y = player->y - y_tmp;
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x - 1, y, ray))
		return ;
	x_tmp = -1;
	y_tmp = +x_tmp * tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x - 1, y, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_v_inter(t_ray *ray, t_map *map, t_player *player) // Sur une grille, vérifie toutes les intersections horizontales du rayon lancé et stocke la distance entre le joueur et le mur touché
{
	ray->size = 0;
	if (ray->angle == deg_transform(90) || ray->angle == deg_transform(270)) // Le joueur est orienté directement vers l'ouest ou l'est. Pour le lancer de rayons, cela signifie que le rayon sera parallèle aux lignes de la grille et ne trouvera jamais d'intersection. Nous lui donnons une valeur très haute pour qu'il soit exclu que ce soit le rayon le plus court
	{
		ray->size = INT_MAX;
		return ;
	}
	if (ft_west(ray->angle))
		ft_get_v_inter_we(ray, map, player);
	else
		ft_get_v_inter_ea(ray, map, player);
}