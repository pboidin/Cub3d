#include "../includes/cub.h"

void	update_position(game_t *game, int tmp_x, int tmp_y)
{
	game->x_player = tmp_x + 30;
	game->y_player = tmp_y + 30;
	game->x_wall = game->x_player + (cos(game->angle) * 40);
	game->y_wall = game->y_player + (sin(game->angle) * 40);
}

void	angle_player(game_t *game, char c)
{
	if (c == 'N')
		game->angle = 4.712389;
	else if (c == 'S')
		game->angle = 1.5708;
	else if (c == 'W')
		game->angle = 3.141592;
	else if (c == 'E')
		game->angle = 0;
}

void	position_map_player(game_t *game)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	init_var(&i, &tmp_y);
	while (game->map[i] != NULL)
	{
		init_var(&j, &tmp_x);
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				angle_player(game, game->map[i][j]);
				game->map[i][j] = '0';
				update_position(game, tmp_x, tmp_y);
			}
			j++;
			tmp_x += 60;
		}
		i++;
		tmp_y += 60;
	}
}