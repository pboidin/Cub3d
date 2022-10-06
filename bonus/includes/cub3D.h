/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:32:41 by madelaha          #+#    #+#             */
/*   Updated: 2022/10/04 15:15:11 by madelaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FALSE 0
# define TRUE 1
# define BUFFER_SIZE 1
# include "../../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <limits.h>

# define EAST 11
# define WEST 12
# define NORTH 13
# define SOUTH 14
# define PI 3.141592635

# define SCALE 64
# define VIEW_ANGLE 60

# define MAX_LINE 200000

# ifndef OS
#  define K_ESC 65307
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_LEFT_ARROW 65361
#  define K_RIGHT_ARROW 65363
# endif

# ifndef OS
#  define DESTROY_NOT 17
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_DESTROY_NOT 131072
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# else
#  define DESTROY_NOT 33
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_DESTROY_NOT 0
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# endif

typedef struct s_map
{
	char	**map;
	int		c_no;
	int		c_so;
	int		c_we;
	int		c_ea;
	int		start_pos;
	int		x_player;
	int		y_player;
	char	*floor;
	char	*ceiling;
	char	*f_r;
	char	*f_g;
	char	*f_b;
	char	*c_r;
	char	*c_g;
	char	*c_b;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_map;

typedef struct s_ray
{
	char		obst;
	char		orienta;
	char		side;
	double		x;
	double		y;
	double		size;
	double		angle;
	double		x_step;
	double		y_step;
}				t_ray;

typedef struct s_rays
{
	t_ray		*arr;
	double		angle_view;
	double		dist_proj;
}				t_rays;

typedef struct s_player
{
	char		walk_dir;
	double		x;
	double		y;
	double		radius;
	double		speed;
	double		rot_ang;
	double		rot_speed;
	int			turn_dir;
}				t_player;

typedef struct s_colo
{
	int			r;
	int			g;
	int			b;
	int			argb;
}				t_colo;

typedef struct s_reso
{
	int	width;
	int	height;
}				t_reso;

typedef struct s_mapi
{
	char		**map;
	int			width;
	int			height;
}				t_mapi;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct s_text
{
	char		*path;
	t_img		img_tex;
	int			width;
	int			height;
}				t_text;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct s_line
{
	int			beg_x;
	int			beg_y;
	int			end_x;
	int			end_y;
	int			col;
	int			wid;
}				t_line;

typedef struct s_circle // Pour Bonus
{
	int			x;
	int			y;
	double		rad;
	int			col;
	int			border_col;
	int			border_wid;
}				t_circle;

typedef struct s_rect
{
	int			x;
	int			y;
	double		wid;
	double		hei;
	int			fill_col;
	int			bord_col;
	int			bord_wid;
	t_text		tex;
}				t_rect;

typedef struct s_disp
{
	t_mapi		map;
	t_reso		reso;
	t_text		no_tex;
	t_text		so_tex;
	t_text		we_tex;
	t_text		ea_tex;
	t_colo		floor;
	t_colo		ceilling;
	int			mini_map; //BONUS
}				t_disp;

typedef struct s_game
{
	t_mlx		mlx;
	t_disp		disp;
	t_player	player;
	t_rays		rays;

}				t_game;

//_________________INIT_PARSING___________

int		ft_init_rgb(t_map *ma_map);
void	ft_init_map(t_map *ma_map);
int		ft_first_init(char **av);
void	ft_init_count_text(t_map *ma_map);

//________________UTILS__________________

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
int		ft_tablen(char **tab);
void	ft_error(void);
void	ft_free(char **tab);

//________________UTILS2_________________

char	*ft_strdup(const char *s1);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
void	ft_free_rgb(t_map *ma_map);
void	ft_is_rgb2(t_map *ma_map, char **map, int i, int j);

//________________GNL____________________

int		ft_check(char *str, char c);
char	*ft_concat(char *str, char *buffer);
char	*ft_get_line(char *str);
char	*ft_get_next(char *str, char *line);
char	*get_next_line(int fd);

//_______________PARSING_________________

int		ft_name_file(char **av);
int		ft_open_file(char **av);
char	**ft_parse_map(char **av);
int		ft_parse_rgb(t_map *ma_map, char **av);
int		ft_is_rgb(t_map *ma_map, char **av);
int		ft_rgb_correct(t_map *ma_map);
int		ft_verif_ceiling(t_map *ma_map);
int		ft_verif_floor(t_map *ma_map);
int		ft_floor(t_map *ma_map);
int		ft_ceiling(t_map *ma_map);
int		ft_check_f(t_map *ma_map);
int		ft_check_c(t_map *ma_map);
void	ft_skip_space(char *str, int *j);
int		ft_parse_dup_text(t_map *ma_map, char **av);
int		ft_parse_dup_rgb(char **av);
int		ft_check_first_line(char *str);
int		ft_check_last_line(char *str);
int		ft_pos(char c);
int		ft_check_inside_map(t_map *ma_map, char *str);
int		ft_z_or_o(char c);
int		ft_first_char(char *str);
int		ft_check_zero(char *line_up, char *line_do, char *line, int j);
int		ft_last_character(char *str);
int		ft_check_next_line(char *str);
int		ft_final_check(t_map *ma_map, char **map);
int		ft_check_inside_first_line(t_map *ma_map, char **map, int i,
			int *count);
int		ft_check_inside_line(t_map *ma_map, char **map, int i, int j);
int		ft_check_map(t_map *ma_map, char **av);
int		ft_check_floor(t_map *ma_map);
int		ft_check_ceiling(t_map *ma_map);
int		ft_first_step_rgb(t_map *ma_map, char **av);
void	ft_skip_space2(char *str, int *j);
void	ft_free_color(t_map *ma_map);
char	*ft_strdup2(const char *s);
int		ft_exit(t_map *ma_map, char **map);

//________________CHECK_MAP__________________

int		ft_check_map(t_map *ma_map, char **av);

//__________________TOOL_BOX_1__________________

void	free_map(t_mapi *map);
void	ft_free_disp(t_disp *disp);
void	ft_free_game(t_game *game);
double	deg_transform(double deg);
double	ft_radian_norm(double rad);

//__________________TOOL_BOX_2__________________

int		ft_south(double angle);
char	ft_get_wall_orient(t_mapi *map, int x, int y, t_ray *ray);
int		ft_wall(t_mapi *map, double x, double y, t_ray *ray);
char	*ft_strchr(const char *s, int c);
void	ft_draw_rect(t_rect *rect, int *img, int reso_wid);

//__________________TOOL_BOX_3__________________

int		ft_west(double angle);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_init_null(t_map *ma_map);

//__________________TOOL_BOX_4__________________

void	ft_free_path(t_map *ma_map);
void	ft_draw_circle(t_circle *circle, int *img, int reso_wid);
void	ft_draw_line(t_line *line, int *img, int reso_wid);

//___________________INIT_STRUCT_______________

void	ft_init_struct(t_map *ma_map, t_disp *disp);
int		ft_save_height(char **map);
int		ft_save_width(char **map);

//____________________LAUNCH_GAME_________________

int		ft_next_frame(void *struc);
int		ft_launch_game(t_game *game, t_map *map);

//____________________GAME_INIT____________________

void	ft_game_init(t_game *game, t_map *map);

//____________________PLAYER_INIT_________________

double	ft_start_orient(char orient);
void	ft_start_position(char **map, t_player *player);
void	ft_init_player(t_game *game);

//____________________EVENTS_INIT_________________

int		ft_close_win(int key, t_game *game);
int		ft_key_relea(int key, t_game *game);
int		ft_key_press(int key, t_game *game, t_map *map);
void	ft_init_events(t_game *game);

//____________________INIT_GAME___________________

void	ft_load_text(void *mlx, t_text *texture);
void	ft_set_rays(t_game *game);
void	ft_init_game(t_game *game);

//____________________UPDATE_______________________

void	ft_upd_rays(t_game *game);
void	ft_upd_player_ori(t_player *player);
void	ft_upd_player_pos(char **grid, t_player *player);
void	ft_updating(t_game *game);

//___________________RAYCAST________________________

void	ft_raycast(t_ray *ray, t_mapi *map, t_player *player);

//___________________RAYCAST_H______________________

void	ft_get_h_inter_no(t_ray *ray, t_mapi *map, t_player *player);
void	ft_get_h_inter_so(t_ray *ray, t_mapi *map, t_player *player);
void	ft_get_h_inter(t_ray *ray, t_mapi *map, t_player *player);

//____________________RAYCAST_V______________________

void	ft_get_v_inter_ea(t_ray *ray, t_mapi *map, t_player *player);
void	ft_get_v_inter_we(t_ray *ray, t_mapi *map, t_player *player);
void	ft_get_v_inter(t_ray *ray, t_mapi *map, t_player *player);

//_____________________DRAW___________________________

void	ft_draw_ceilling(t_game *game);
void	ft_draw_floor(t_game *game);
void	ft_drawing(t_game *game);

//_____________________DRAW_WALL_______________________

t_text	ft_get_wall_tex(t_disp *disp, char orienta);
int		ft_get_y_wall_pos(t_game *game, double wall_hei);
double	ft_get_hei_wall(t_game *game, t_ray *ray);
void	ft_draw_wall(t_game *game);

//______________________DRAW_WALL_UTILS_________________

int		ft_bit_mapper(t_ray *ray, int bitmap_wi);
void	ft_draw_strip_w(t_rect *rect, int *img, t_reso *reso, t_ray *ray);

//_______________________MAP_____________________________

void	ft_draw_rays(t_game *game, double size);
void	ft_draw_player(t_game *game, double size);
int		ft_color(t_colo *col_floor, char grid);
void	ft_draw_map(t_game *game);
void	ft_draw_mini_map(t_game *game);

#endif
