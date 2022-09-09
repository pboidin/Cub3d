#ifndef	CUB_H
# define CUB_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "gnl/get_next_line.h"

# define EAST 11
# define WEST 12
# define NORTH 13
# define SOUTH 14
# define PI 3.141592635
# define BUFFER_SIZE 10000

typedef struct	game_s
{
//Nom des textures
	char	*name_tex_NO;
	char	*name_tex_SO;
	char	*name_tex_WE;
	char	*name_tex_EA;

	char	*addr;
	char	*addr_tex;
	char	**map;
	
//Taille des textures
	int		hei_tex;
	int		wid_tex;

	int		side;
	int		f_side;
	int		Ceiling_col[3];
	int		Floor_col[3];
	int		bits_per_pixel;
	int 	line_lenght;
	int		line_lenght_tex;
	int 	endian;
	int		x_prime;
	int		nb_rays;
	int		orientation;

	float	x_player;
	float	y_player;
	float	x_wall;
	float	y_wall;
	float	hor_inter;
	float	ver_inter;
	float	angle;


//Image de la Window
	void	*img;

	void	*mlx_ptr;
	void	*win_ptr;
//Textures
	void	*texture_NO;
	void	*texture_SO;
	void	*texture_WE;
	void	*texture_EA;

	void	*view_ptr;

}		game_t;

// Cette structure va récupérer les données des textures lors du parsing
typedef struct	info_s
{
	char	*NO_tex;
	char	*SO_tex;
	char	*WE_tex;
	char	*EA_tex;
	int	*CE_col;
	int	*FL_col;
}		info_t;

typedef struct map_check
{
	int	no_tex;
	int	so_tex;
	int	ea_tex;
	int	we_tex;
	int	flo_col;
	int	cel_col;
}		t_mapCheck;

//Change_Texture
int		ft_change_texture(game_t *game);

//Check_args
char	**ft_check_args(int argc, char **argv);
void	ft_message_exit(char **ptr);

//Check_Button
void	check_up_button(game_t *game);
void	check_down_button(game_t *game);
void	check_left_button(game_t *game);
void	check_right_button(game_t *game);

//game_info
char    **game_in(char **file);

//Get_Next_Line
int		check_nl(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int file_d);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int file_d);
char	*get_before_nl(char *buf, int opt);
char	*join_and_free(char *ret, char *buf);
void	get_after_nl(char *buf);
void	ft_zero(char *buf);

//Init_game
void    check_texture(void *texN, void *texS, void *texW, void *texE);
void    init_color(game_t *game, info_t *info);
void    game_init(game_t *game, info_t *info);

//Init_info
int     is_c_or_f(char *str);
void    init_rgb(info_t *info, char *str);
int     is_tex(char *str);
void    init_tex(info_t *info, char *str);
void    info_init(info_t *info, char **file);

//Player_move
int 	player_move(int key, game_t *game);

//Player_position
void	update_position(game_t *game, int tmp_x, int tmp_y);
void	angle_player(game_t *game, char c);
void	position_map_player(game_t *game);

//Raycasting
int		check_x_axis(game_t *game, long int x, long int y);
int		check_y_axis(game_t *game, long int x, long int y);
void	raycasting(game_t *game);

//Tools_box
char    *ft_strdup(char *str);
char    *delete_nl(char *str);
void    malloc_err(void);
void    skip_spaces(char *str, int *i);
void    ft_skip_spaces(char *str, int *i);

int     ft_atoi(char *str, int *i);
void	init_var(int *i1, int *i2);

#endif
