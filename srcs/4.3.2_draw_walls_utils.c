#include "../includes/cub.h"

int		ft_bit_mapper(t_ray *ray, int bitmap_wi) // En se basant sur l'endroit exact où le rayon frappe le mur, nous pouvons trouver quelle partie de la texture à utiliser pour le mur
{
	double	re;
	int		offset;

	if (ray->side == 'H') // //Savoir si ce rayon est horizontal ou vertical (cf. cast_ray.c) nous permet de savoir quelle coordonnée de rayon aura une partie fractionnaire car s'il s'agit d'un mur, les coordonnées sont nécessairement du format format x:1.00/y:2.42 ou x:1.42/y:2.00
	{
		re = ray->x - floor(ray->x);
		offset = bitmap_wi * re; // Multiplier un nombre comme 64 par un autre compris entre 0 et 1 plafonne le résultat à 64. Offset est un int car il sera utilisé comme un index de tableau
	}
	else
	{
		re = ray->y - floor(ray->y);
		offset = bitmap_wi * re;
	}
	return (offset);
}

void	ft_draw_strip_w(t_rect *rect, int *img, t_reso *reso, t_ray *ray)
{
	int		y;
	int		x_text;
	int		y_text;
	double	tmp;
	double	tex;

	tmp = 1.0 * rect->tex.height / rect->hei; // Plus le joueur est éloigné de l'écran, moins il y a de pixels à dessiner, donc plus le pas est grand, plus il est éloigné du sprite.
	tex = (rect->y - reso->height / 2 + rect->hei / 2) * tmp;
	x_text = ft_bit_mapper(ray, rect->tex.width); // Trouve quelle texture a utiliser sur le mur
	y = -1;
	while (++y , rect->hei && y < rect->tex.height)
	{
		y_text = (int)tex & (rect->tex.height - 1);
		tex += tmp;
		img[(rect->y * reso->width) + (y * reso->width) + rect->x] = rect->tex.img_tex.data[y_text + rect->tex.height + x_text];
	}
}