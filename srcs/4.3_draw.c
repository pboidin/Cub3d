#include "../includes/cub.h"

void	ft_draw_ceilling(t_game *game) // Dessine un grand rectangle de la taille de la moitié de l'écran avec la couleur indiquée dans le fichier .cub
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.wid = game->disp.reso.width;
	rect.hei = game->disp.reso.height / 2;
	rect.bord_wid = 0;
	rect.fill_col = game->disp.ceilling.argb;
	ft_draw_rect(&rect, game->mlx.img.data, game->disp.reso.width);
}

void	ft_draw_floor(t_game *game) // Dessine un grand rectangle de la taille de la moitié de l'écran avec la couleur indiquée dans le fichier .cub
{
    t_rect	rect;

	rect.x = 0;
	rect.y = game->disp.reso.height / 2;
	rect.wid = game->disp.reso.width;
	rect.hei = game->disp.reso.height / 2;
	rect.bord_wid = 0;
	rect.fill_col = game->disp.floor.argb;
	ft_draw_rect(&rect, game->mlx.img.data, game->disp.reso.width);
}

void	ft_drawing(t_game *game) // Fonction appelée une fois par image après la mise à jour de la structure du jeu. Elle dessine les éléments sur un img. L'ordre est important car certains éléments écrasent d'autres.
{
	ft_draw_ceilling(game);
    ft_draw_floor(game);
	ft_draw_wall(game);
}