/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/31 19:34:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define R_WIDTH 1000
# define R_HEIGHT 1000

# define OK 0
# define KO 1 

typedef enum s_cardinal_points
{
	EAST,
	SOUTH,
	WEST,
	NORTH,
	NORTHEAST,
	SOUTHEAST,
	SOUTHWEST,
	NORTHWEST,
}	t_cardinal_points;

typedef struct s_player
{
	t_point	pos;
	t_point	hit1;
	t_point	hit2;
	t_point	f_hit;
	char	dir;
	int		angle;
}	t_player;

typedef struct s_map
{
	char		**grid;
	t_size		size;
	t_player	player;
}				t_map;

typedef struct	s_texture
{
	char		*path;
	char		*addr;
	void		*img;
	int			img_width;
	int			img_height;
	int			bpp;
	int			line_lenght;
	int			endian;
}				t_texture;

typedef struct s_screen
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
}				t_screen;

typedef struct	s_args
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_player	player;
}				t_args;

typedef struct s_ray
{
	double	*hypo;
	double	dist;
	int		wall_height;
	int		floored_wall_height;
	char	dir;
}			t_ray;

typedef struct s_data
{
	t_args			args;
	t_minimap		minimap;
	void			*mlx_ptr;
	void			*win_ptr;
	t_screen		buff1;
	t_screen		buff2;
	t_ray			ray;
	int				frame;
}	t_data;

void	not_real_data(t_data *data);
int		load_textures(t_data *data, t_args *args);

void	render_scene(t_data *data, t_screen *buff);
double	update_angle(double angle, double rotation);
void	calculate_wall_height(t_data *data, double angle, double tmp);
double	calculate_distance_to_wall(t_data *data, double angle);
double	detect_wall_distance_east(t_data *data);
double	detect_wall_distance_west(t_data *data);
double	detect_wall_distance_south(t_data *data);
double	detect_wall_distance_north(t_data *data);

void	draw_textured_column(t_data *data, t_screen *buff, int x, int y);
t_texture	*choose_texture(t_data *data);
double	calculate_hit_decimal(t_data *data);
char	check_hit(t_data *data, char hit, double x, double y);

double	sw(t_data *data, t_point decimal, double angle);
double	sw_1(t_data *data, t_point decimal, double angle);
double	sw_2(t_data *data, t_point decimal, double angle);
double	*sw_y(t_data *data, t_point decimal, double angle);
double	sw_y_1(t_data *data, t_point decimal, double angle);
double	*sw_x(t_data *data, t_point decimal, double angle);
double	sw_x_1(t_data *data, t_point decimal, double angle);

double	se(t_data *data, t_point decimal, double angle);
double	se_1(t_data *data, t_point decimal, double angle);
double	se_2(t_data *data, t_point decimal, double angle);
double	*se_y(t_data *data, t_point decimal, double angle);
double	se_y_1(t_data *data, t_point decimal, double angle);
double	*se_x(t_data *data, t_point decimal, double angle);
double	se_x_1(t_data *data, t_point decimal, double angle);

double	nw(t_data *data, t_point decimal, double angle);
double	nw_1(t_data *data, t_point decimal, double angle);
double	nw_2(t_data *data, t_point decimal, double angle);
double	*nw_y(t_data *data, t_point decimal, double angle);
double	nw_y_1(t_data *data, t_point decimal, double angle);
double	*nw_x(t_data *data, t_point decimal, double angle);
double	nw_x_1(t_data *data, t_point decimal, double angle);

double	ne(t_data *data, t_point decimal, double angle);
double	ne_1(t_data *data, t_point decimal, double angle);
double	ne_2(t_data *data, t_point decimal, double angle);
double	*ne_y(t_data *data, t_point decimal, double angle);
double	ne_y_1(t_data *data, t_point decimal, double angle);
double	*ne_x(t_data *data, t_point decimal, double angle);
double	ne_x_1(t_data *data, t_point decimal, double angle);

void	turn(int keycode, t_data *data);
void	move(int keycode, t_data *data);
void	keycode(int keycode, t_data *data);
int		next_frame(int keycode, t_data *data);

#endif
