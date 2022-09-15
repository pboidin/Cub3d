#ifndef	CUB_H
# define CUB_H

# include "constants.h"
# include "structs.h"
# include "./minilibx_macos/mlx.h"

// Attente
void	check_arguments(int argc, char **argv);

//Tools Box
double	deg_transform(double deg);
void	ft_free_game(t_game *game);
double	ft_radian_norm(double rad);
void	ft_draw_rect(t_rect *rect, int *img, int reso_wid);
char	*ft_strchr(const char *s, int c);
int		ft_south(double angle);
int		ft_wall(t_map *map, double x, double y, t_ray *ray);
int     ft_west(double angle);

//--LAUNCH GAME--
int		ft_launch_game(t_game *game);

//---GAME INIT---
void    ft_game_init(t_game *game);
void	ft_init_player(t_game *game);
void	ft_init_events(t_game *game);
void	ft_init_game(t_game *game);

//---UPDATE---
void	ft_get_h_inter(t_ray *ray, t_map *map, t_player *player);
void	ft_get_v_inter(t_ray *ray, t_map *map, t_player *player);
void	ft_raycast(t_ray *ray, t_map *map, t_player *player);
void	ft_updating(t_game *game);

//---DRAW---
void	ft_draw_wall(t_game *game);
void	ft_drawing(t_game *game);

#endif