/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:42:51 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 16:35:40 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../parsing/cub_parsing.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define MOVE_UP 13
# define MOVE_DOWN 1
# define MOVE_RIGHT 2
# define MOVE_LEFT 0
# define TURN_LEFT 123
# define TURN_RIGHT 124
# define ESC 53

# define WINDOWS_WIDTH 1200
# define WINDOWS_HEIGHT 900
# define TILE_SIZE 64
# define TILE_SIZE1 20
# define PI M_PI
# define HALF_PI 1.57079632679489661923
# define FOV 1.0471975512
# define RAYTHIK 1
# define TRUE 1
# define FALSE 0
# define MINI_MAP_SCALE 1
# define RED 0XFF0000
# define BLACK 0X000000
# define WHITE 0XFFFFFF
# define SKY_COLOR 0x000080
# define GROUND_COLOR 0x00777777

typedef struct s_coordonner
{
	float			x;
	float			y;
}					t_coordonner;

typedef struct s_player
{
	int				x;
	int				y;
	int				move_speed;
	double			rot_angle;

}					t_player;

typedef struct s_rays
{
	int				wall_x;
	int				wall_y;
	int				hit_horizontal;
	float			ray_angle;
	float			distance_to_wall;
}					t_rays;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx;

typedef struct s_map1
{
	char			**map;
	int				len_x;
	int				len_y;
	int				tile_size;
	unsigned int	ciel;
	unsigned int	floor;
}					t_map1;

typedef struct s_color
{
	int				red;
	int				black;
	int				pink;
	int				white;
}					t_color;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

}					t_img;

typedef struct s_DDA
{
	float			start_x;
	float			start_y;
	float			dx;
	float			dy;
	int				direction_flag;
}					t_DDA;

typedef struct s_texture
{
	t_img			north_texture;
	int				tex_north_height;
	int				tex_north_width;
	int				tex_south_height;
	int				tex_south_width;
	int				tex_west_height;
	int				tex_west_width;
	int				tex_est_height;
	int				tex_est_width;
	int				tex_door_height;
	int				tex_door_width;
	t_img			south_texture;
	t_img			west_texture;
	t_img			est_texture;
	t_img			door_texture;
}					t_texture;

typedef struct s_texture1
{
	t_img			texture;
	int				height;
	int				width;
}					t_texture1;

typedef struct s_event
{
	int				key_up;
	int				key_down;
	int				key_left;
	int				key_right;
	int				left_arrow;
	int				right_arrow;
	int				esc;
}					t_event;

typedef struct s_animation
{
	void	**shooting_frames;
	int		width[6];
	int		height[6];
	int		index;
	int		timer;
	int		start_frames;
	char	**frames;
}					t_animation;

typedef struct s_game_play
{
	t_img			img;
	t_player		player;
	t_map1			map;
	t_color			color;
	t_mlx			mlxxx;
	t_texture		texture;
	t_rays			rays;
	int				old_x;
	int				current_x;
	t_event			key_event;
	t_parsing		pars;
	t_animation		*animation;
}					t_game_play;

typedef struct s_calcul_texture
{
	t_texture1		tex;
	float			scaler;
	int				offset_x;
	int				column_offset;
}					t_calcul_texture;

void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
void				lenx_leny_of_map(char **map, int *x, int *y);
char				**dup_map(char **map);
void				initialize_game_play(t_game_play *game_play,
						t_parsing *parsing1);
void				player_position(char **map, int *x, int *y);
t_rays				dda(t_game_play *game, double rayAngle);
int					ft_collision(t_game_play *game_play, int x, int y);
int					lookin_up(double angle);
int					lookin_down(double angle);
int					lookin_right(double angle);
int					lookin_left(double angle);
void				move_it(t_game_play *game_play, double angle,
						int direction);
void				move_player(void *param);
void				rotate_player(void *param);
void				ft_draw_loop(t_game_play *game_play);
double				ft_angle(double angle);
void				ft_put_ground(t_game_play *game, int start_x, int start_y,
						int WallHeigth);
void				ft_put_wall(t_game_play *game, int start_x, int start_y,
						int WallHeigth);
void				ft_put_cub(t_game_play *game, int start_x, int start_y,
						int WallHeigth);
void				ft_put_sky(t_game_play *game, int start_x, int start_y);
void				ft_draw(t_img *img, int x, int y, int color);
void				draw_line(t_img *img, double angle);
void				ft_draw_player(t_img *img, int color);
void				draw_rays(t_game_play *game);
t_rays				*ft_get_rays(t_game_play *game);
int					is_hit_wall(t_game_play *game_play, int pos_x, int pos_y);
int					close_window(t_game_play *game_play);
unsigned int		get_color(t_texture1 tex, int index);
void				determine_texture(t_game_play *game, t_texture1 *tex);
void				initialize_text_door(t_game_play *game_play,
						t_parsing *parsing1);
void				initialize_text_east(t_game_play *game_play,
						t_parsing *parsing1);
void				initialize_text_west(t_game_play *game_play,
						t_parsing *parsing1);
void				initialize_text_south(t_game_play *game_play,
						t_parsing *parsing1);
void				initialize_text_north(t_game_play *game_play,
						t_parsing *parsing1);
int					ft_abs(int x);
double				ft_angle(double angle);
int					mouse_event(int x, int y, void *param);
int					mouse_event1(int x, int y, void *param);
void				ft_print_map(char **p);
int					key_realsed(int keycode, void *param);
int					key_pressed1(int keycode, void *param);
void				start_direction(t_game_play *game_play);
void				initialize_event_key(t_game_play *game_play);
int					ft_strcmp1(char *str1, char *str2);
void				left_rotation(t_game_play *game_play);
void				right_rotation(t_game_play *game_play);
void				render_player(t_game_play *game);
char				**ft_initialize(t_animation *anim);
void				ft_animation_1(t_game_play *game_play);
void				print_and_exit1(char *str);
void				ft_animation(t_game_play *game_play, t_animation *anim);
int					key_pressed(void *param);
#endif