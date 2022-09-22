#ifndef	CUB_H
# define CUB_H

# include "constants.h"
# include "structs.h"
# include "../libraries/minilibx-linux/mlx.h"
# define MAX_LINE 200000

// Attente
void		check_arguments(int ac, char **av);
int		    check_extension(char *file, char *extension);
void		ft_take_map(int fd, char *line, t_map *map);
void		ft_init_struct(int fd, t_disp *disp);
int			is_map(char *line);
void	    ft_check_map(t_disp *disp);


//Tools Box
double		deg_transform(double deg);
void		ft_free_game(t_game *game);
double		ft_radian_norm(double rad);
void		ft_draw_rect(t_rect *rect, int *img, int reso_wid);
char		*ft_strchr(const char *s, int c);
int			ft_south(double angle);
int			ft_wall(t_map *map, double x, double y, t_ray *ray);
int			ft_west(double angle);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		**ft_split(char *str, char *cstr);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(const char *s);
int			ft_strchr_f(const char *s, int c);
int			ft_strisdigit(char *s);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
void		free_str(char **str);
void		*ft_realloc(void *p, size_t old_s, size_t new_s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			get_next_line(int fd, char **line);
void		ft_realloc_protec(void **p, size_t old_s, size_t new_s);
char		*ft_strncpy(char *dst, char *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);

//--LAUNCH GAME--
int			ft_launch_game(t_game *game);

//---GAME INIT---
void		ft_game_init(t_game *game);
void		ft_init_player(t_game *game);
void		ft_init_events(t_game *game);
void		ft_init_game(t_game *game);

//---UPDATE---
void		ft_get_h_inter(t_ray *ray, t_map *map, t_player *player);
void		ft_get_v_inter(t_ray *ray, t_map *map, t_player *player);
void		ft_raycast(t_ray *ray, t_map *map, t_player *player);
void		ft_updating(t_game *game);

//---DRAW---
void		ft_draw_wall(t_game *game);
void		ft_drawing(t_game *game);
void		ft_draw_strip_w(t_rect *rect, int *img, t_reso *reso, t_ray *ray);

#endif