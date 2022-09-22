#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_ray
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

typedef struct	s_rays
{
	t_ray		*arr;
	double		angle_view;
	double		dist_proj;
}				t_rays;


typedef struct	s_player
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

typedef struct	s_colo
{
	int			r;
	int			g;
	int			b;
	int			argb;
}				t_colo;

typedef struct	s_reso
{
	int	width;
	int	height;
}				t_reso;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_text
{
	char		*path;
	t_img		img_tex;
	int			width;
	int			height;
}				t_text;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct	s_rect
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

typedef struct	s_disp
{
	t_map		map;
	t_reso		reso;
	t_text		NO_tex;
	t_text		SO_tex;
	t_text		WE_tex;
	t_text		EA_tex;
	t_colo		floor;
	t_colo		ceilling;	
}				t_disp;

typedef struct	s_game
{
	t_mlx		mlx;
	t_disp		disp;
	t_player	player;
	t_rays		rays;

}				t_game;

#endif