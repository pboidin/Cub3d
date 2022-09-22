#include "../includes/cub.h"

void    ft_game_init(t_game *game)
{
    ft_init_player(game);
    ft_init_events(game);
    ft_init_game(game);
}