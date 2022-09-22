#include "../includes/cub.h"

int		ft_close_win(int key, t_game *game) // Fonction appelée chaque fois que l'utilisateur a essayé de fermer la fenêtre (ALT FT ou croix de la fenêtre)
{
	(void)key;
	(void)game;
	exit(EXIT_SUCCESS);
	return (1);
}

int		ft_key_relea(int key, t_game *game) // Fonction appelée à chaque fois qu'une touche est relachée.
{
	(void)game;
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		game->player.walk_dir = 0;
	else if (key == K_LEFT_ARROW || key == K_RIGHT_ARROW)
		game->player.turn_dir = 0;
	return (1);
}

int		ft_key_press(int key, t_game *game) // Fonction appelée à chaque fois qu'une touche est pressée
{
    if (key == K_W)
    	game->player.walk_dir = 'w';
    else if (key == K_A)
        game->player.walk_dir = 'a';
    else if (key == K_S)
        game->player.walk_dir = 's';
    else if (key == K_D)
        game->player.walk_dir = 'd';
    else if (key == K_LEFT_ARROW)
        game->player.walk_dir = -1;
    else if (key == K_RIGHT_ARROW)
        game->player.walk_dir = 1;
    else if (key == K_ESC)
    {
    	ft_free_game(game);
        exit(EXIT_SUCCESS);
    }
    return (1);
}

void	ft_init_events(t_game *game)
{
    mlx_do_key_autorepeatoff(game->mlx.mlx_ptr); // Par défaut, les événements liés à l'appui sur les touches de x11 sont en mode répétition automatique (c'est-à-dire que l'appui sur une touche déclenche alternativement des événements d'appui et de relâchement événements)
    mlx_hook(game->mlx.win_ptr, KEY_PRESS, M_KEY_PRESS, ft_key_press, game);
	mlx_hook(game->mlx.win_ptr, KEY_RELEASE, M_KEY_RELEASE, ft_key_relea, game);
	mlx_hook(game->mlx.win_ptr, DESTROY_NOT, M_DESTROY_NOT, ft_close_win, game);
}