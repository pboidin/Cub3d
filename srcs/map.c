#include "../includes/cub.h"

void	ft_draw_rays(t_game *game, double size)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < game->disp.reso.width)
	{
		line.beg_x = game->player.x * size + 10;
		line.beg_y = game->player.y * size + 10;
		line.end_x = game->player.x * size + 10
			+ cos(game->rays.arr[i].angle)
			* size * game->rays.arr[i].size;
		line.end_y = game->player.y * size + 10
			+ sin(game->rays.arr[i].angle)
			* size * game->rays.arr[i].size;
		line.col = 0x00F6B8BD;
		ft_draw_line(&line, game->mlx.img.data, game->disp.reso.width);
	}
}

void	ft_draw_player(t_game *game, double size)
{
	t_circle	circle;

	ft_draw_rays(game, size);
	game->player.radius = ceil(size / 2);
	circle.x = game->player.x * size + 10;
	circle.y = game->player.y * size + 10;
	circle.rad = game->player.radius;
	circle.col = 0x00e63946;
	while (circle.rad--)
		ft_draw_circle(&circle, game->mlx.img.data, game->disp.reso.width);
}

int		ft_color(t_colo *col_floor, char grid)
{
	int	col;

	if (grid == '1')
		col = col_floor->argb;
	else
		col = 0x00FFFFFF;
	return (col);
}

void	ft_draw_map(t_game *game)
{
	char	grid;
	int		i;
	int		j;
	t_rect	rect;

	i = -1;
	while (++i < game->disp.map.height)
	{
		j = -1;
		while (++j < game->disp.map.width)
		{
			grid = game->disp.map.map[i][j];
			if (grid == ' ')
				continue;
			rect.x = j * game->disp.mini_map + 10;
			rect.y = i * game->disp.mini_map + 10;
			rect.wid = game->disp.mini_map;
			rect.hei = game->disp.mini_map;
			rect.bord_col = 0x0014213d;
			rect.bord_wid = 1;
			rect.fill_col = ft_color(&game->disp.floor, grid);
			ft_draw_rect(&rect, game->mlx.img.data, game->disp.reso.width);
		}
		
	}
	
}

void	ft_draw_mini_map(t_game *game)
{
	int	map_hei;

	map_hei = game->disp.mini_map * game->disp.map.height + 10 * 2;
	if (map_hei > game->disp.reso.height)
		return ;
	ft_draw_map(game);
	ft_draw_player(game, game->disp.mini_map);
}