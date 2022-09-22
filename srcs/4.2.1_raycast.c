#include "../includes/cub.h"

void	ft_raycast(t_ray *ray, t_map *map, t_player *player) // Lance 2 rayons pour déterminer la distance entre le joueur et le mur. Un rayon vérifie l'intersection horizontale de la grille et l'autre l'intersection verticale. Le rayon le plus court est conservé comme distance entre le joueur et le mur pour déterminer la hauteur du mur.
{
	t_ray	h_inter;
	t_ray	v_inter;

	h_inter.angle = ft_radian_norm(ray->angle);
	v_inter.angle = ft_radian_norm(ray->angle);
	h_inter.side = 'H';
	v_inter.side = 'V';
	ft_get_h_inter(&h_inter, map, player);
	ft_get_v_inter(&v_inter, map, player);
	if (h_inter.size <= v_inter.size)
		*ray = h_inter;
	else
		*ray = v_inter;
}