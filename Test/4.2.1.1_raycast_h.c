#include "cub.h"

void	ft_get_h_inter_no(t_ray *ray, t_map *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	y = floor(player->y); // Nous devons arrondir à la baisse pour obtenir l'intersection horizontale suivante.
	y_tmp = player->y - y; // Le flottant moins la valeur arrondie vers le bas nous donne la distance rectiligne à l'intersection horizontale
	x_tmp = y_tmp / tan(ray->angle);
	x = player->x - x_tmp; // Faire un pas en arrière parce que nous passons du bas au haut.
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x, y - 1, ray))
		return ;
	y_tmp = -1; // Tmp doit être négatif car nous passons du bas au haut de la grille.
	x_tmp = +y_tmp / tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x, y - 1, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_h_inter_so(t_ray *ray, t_map *map, t_player *player)
{
	double	x;
	double	y;
	double	x_tmp;
	double	y_tmp;
	double	sect;

	y = ceil(player->y); // Nous devons arrondir à l'unité supérieure pour obtenir l'intersection horizontale suivante.
	y_tmp = y - player->y; // La valeur arrondie moins la valeur flottante 1 nous donne la distance en ligne droite vers l'intersection horizontale
	x_tmp = y_tmp / tan(ray->angle);
	x = player->x + x_tmp; // Faire un pas en avant parce que nous passons du haut vers le bas.
	ray->size += sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	if (ft_wall(map, x, y, ray))
		return ;
	y_tmp = 1; // Tmp doit être positif parce que nous passons du haut au bas de la grille.
	x_tmp = y_tmp / tan(ray->angle);
	sect = sqrt(pow(x_tmp, 2) + pow(y_tmp, 2));
	while (!ft_wall(map, x, y, ray))
	{
		x += x_tmp;
		y += y_tmp;
		ray->size += sect;
	}
}

void	ft_get_h_inter(t_ray *ray, t_map *map, t_player *player) // Sur une grille, vérifie toutes les intersections horizontales du rayon lancé et stocke la distance entre le joueur et le mur touché
{
	ray->size = 0;
	if (ray->angle == deg_transform(180) || ray->angle == deg_transform(360)) // Le joueur est orienté directement vers l'ouest ou l'est. Pour le lancer de rayons, cela signifie que le rayon sera parallèle aux lignes de la grille et ne trouvera jamais d'intersection. Nous lui donnons une valeur très haute pour qu'il soit exclu que ce soit le rayon le plus court
	{
		ray->size = INT_MAX;
		return ;
	}
	if (ft_south(ray->angle))
		ft_get_h_inter_so(ray, map, player);
	else
		ft_get_h_inter_no(ray, map, player);
}