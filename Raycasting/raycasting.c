/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:48:39 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/29 11:11:22 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//	int deltax = end.x_position - start.x_position;
//	int deltay = end.y_position - start.y_position;
//	int steps = 1000;
//
////	if (abs(deltax) >= abs(deltay))
////		steps = abs(deltax) * 1;
////	else if (abs(deltax) < abs(deltay))
////		steps = abs(deltay) * 1;
//	float int_x = abs(deltax) / steps;
//	float int_y = abs(deltay) / steps;
//	int x_ray = start.x_position;
//	int y_ray = start.y_position;
//
//	printf("=>> %d\n", steps);
//	while (steps --)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, x_ray,  y_ray, 0x008000);
//		x_ray += int_x;
//		y_ray += int_y;
//	}

double	convert_to_radians(double value)
{
	return ((value * M_PI) / 180);
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>

// A function to put pixel onto display
void put_pixel_to_display(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

void dda(t_vector start, t_vector end, t_player *player)
{
	// Calculate dx , dy
	int x0 = start.x_position;
	int y0 = start.y_position;
	int x1 = end.x_position;
	int y1 = end.y_position;
	int dx = x1 - x0;
	int dy = y1 - y0;

	// Calculate the number of steps needed
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// Calculate x and y increment for each step
	float x_inc = dx / (float) steps;
	float y_inc = dy / (float) steps;

	// Initialize starting points
	float x = x0;
	float y = y0;

	// Draw the pixels by incrementing x and y
	// at each step by x_inc and y_inc respectively
	for(int i = 0; i <= steps; i++)
	{
		put_pixel_to_display(player->vars->mlx, player->vars->win, round(x), round(y), 0x008000);
		x += x_inc;
		y += y_inc;
	}
}

int	find_hypotenuse(int a, int b)
{
	return (sqrt(a) + sqrt(b));
}

//void	dda(t_vector start, t_vector end, t_player *player)
//{
//	int x0 = start.x_position;
//	int y0 = start.y_position;
//	int x1 = end.x_position;
//	int y1 = end.y_position;
//
//	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
//	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
//	int err = dx + dy, e2; /* error value e_xy */
//
//	while (1)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, x0, y0,  0x008000);
//		if (x0 == x1 && y0 == y1) break;
//		e2 = 2 * err;
//		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
//		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
//	}
//}

int	draw_ray(t_player *player)
{
	t_vector	start;
	t_vector	end;
	t_vector	y_intersection;
	t_vector	x_intersection;
	int			y_end_map = 0;
	int			x_end_map = 0;
	int			count_rows = count_map(player->map->map);
	int			y_map = player->y_player / (HEIGHT / count_rows);
	int 		x_map = (player->x_player * ((int)ft_strlen(player->map->map[y_map]) - 1)) / WIDTH;

	if (player->current_angle == 360 || player->current_angle == -360)
		player->current_angle = 0;
	start.x_position = player->x_player;
	start.y_position = player->y_player;
	y_end_map = y_map;
	x_end_map = x_map;
	while (player->map->map[y_end_map][x_end_map] != '1')
	{
		if ((player->current_angle >= -180 && player->current_angle < 0) || player->current_angle >= 180)
		{
			y_intersection.y_position = (y_map) * (HEIGHT / count_rows);
			y_intersection.x_position = start.x_position + ((abs(y_intersection.y_position - start.y_position)) / (tan(convert_to_radians(player->current_angle))));
			if ((player->current_angle >= -90 && player->current_angle <= 0) || (player->current_angle >= (180 + 90) && player->current_angle >= 0))
			{
				x_intersection.x_position = (x_map) * (WIDTH / (ft_strlen(player->map->map[y_map]) - 1));
				x_intersection.y_position = start.y_position + (tan(convert_to_radians(player->current_angle)) * (abs(x_intersection.x_position - start.x_position)));
			}
			else
			{
				x_intersection.x_position = (x_map + 1) * (WIDTH / (ft_strlen(player->map->map[y_map]) - 1));
				x_intersection.y_position = start.y_position - (tan(convert_to_radians(player->current_angle)) * (abs(x_intersection.x_position - start.x_position)));
			}
			if (find_hypotenuse(abs(x_intersection.x_position - start.x_position), abs(x_intersection.y_position - start.y_position))\
		< find_hypotenuse(abs(y_intersection.x_position - start.x_position), abs(y_intersection.y_position - start.y_position)))
			{
				end.x_position = x_intersection.x_position;
				end.y_position = x_intersection.y_position;
			}
			else
			{
				end.x_position = y_intersection.x_position;
				end.y_position = y_intersection.y_position;
			}
		}
		else
		{
			y_intersection.y_position = (y_map + 1) * (HEIGHT / count_rows);
			y_intersection.x_position = start.x_position - ((abs(y_intersection.y_position - start.y_position)) / (tan(convert_to_radians(player->current_angle))));
			if ((player->current_angle < -(90 + 180) && player->current_angle <= 0) || (player->current_angle <= 90 && player->current_angle >= 0))
			{
				x_intersection.x_position = (x_map) * (WIDTH / (ft_strlen(player->map->map[y_map]) - 1));
				x_intersection.y_position = start.y_position + (tan(convert_to_radians(player->current_angle)) * (abs(x_intersection.x_position - start.x_position)));
			}
			else
			{
				x_intersection.x_position = (x_map + 1) * (WIDTH / (ft_strlen(player->map->map[y_map]) - 1));
				x_intersection.y_position = start.y_position - (tan(convert_to_radians(player->current_angle)) * (abs(x_intersection.x_position - start.x_position)));
			}
			if (find_hypotenuse(abs(x_intersection.x_position - start.x_position), abs(x_intersection.y_position - start.y_position))\
		< find_hypotenuse(abs(y_intersection.x_position - start.x_position), abs(y_intersection.y_position - start.y_position)))
			{
				end.x_position = x_intersection.x_position;
				end.y_position = x_intersection.y_position;
			}
			else
			{
				end.x_position = y_intersection.x_position;
				end.y_position = y_intersection.y_position;
			}
		}
		if ((player->current_angle >= -180 && player->current_angle < 0) || player->current_angle >= 180)
		{
			y_end_map = (end.y_position - 0.0001) / (HEIGHT / count_rows);
			if ((player->current_angle >= -90 && player->current_angle <= 0) || (player->current_angle >= (180 + 90) && player->current_angle >= 0))
				x_end_map = (end.x_position * ((int)ft_strlen(player->map->map[y_end_map]) - 1) - 0.1) / WIDTH;
			else
				x_end_map = (end.x_position * ((int)ft_strlen(player->map->map[y_end_map]) - 1) + 0.1) / WIDTH;
		}
		else
		{
			y_end_map =  (end.y_position /*+ 0.0001*/) / (HEIGHT / count_rows);
			if ((player->current_angle < -(90 + 180) && player->current_angle <= 0) || (player->current_angle <= 90 && player->current_angle >= 0))
				x_end_map = (end.x_position * ((int)ft_strlen(player->map->map[y_end_map]) - 1) - 0.1) / WIDTH;
			else
				x_end_map = (end.x_position * ((int)ft_strlen(player->map->map[y_end_map]) - 1) /*+ 0.001*/) / WIDTH;
		}
		dda(start, end, player);
		start.x_position = end.x_position;
		start.y_position = end.y_position;
		y_map = y_end_map;
		x_map = x_end_map;
	}
	return (1);
}

int render_map(t_player *player)
{
	int 	current_x_corr;
	int 	current_y_corr;
	int 	x;
	int 	y;
	int		count_rows;

//	mlx_clear_window(player->vars->mlx, player->vars->win);
	y = 0;
	count_rows = count_map(player->map->map);
	while (player->map->map[y])
	{
		x = 0;
		while (player->map->map[y][x])
		{
			if (player->map->map[y][x] == '1')
			{
				current_y_corr = ((HEIGHT * y) / count_rows);
				while (current_y_corr < ((HEIGHT * (y + 1)) / count_rows))
				{
					current_x_corr = ((WIDTH * x) / ((int) ft_strlen(player->map->map[y]) - 1));
					while (current_x_corr < ((WIDTH * (x + 1)) / ((int) ft_strlen(player->map->map[y]) - 1)))
					{
						mlx_pixel_put(player->vars->mlx, player->vars->win, current_x_corr, current_y_corr, 0xFFFFFF);
						current_x_corr ++;
					}
					current_y_corr ++;
				}
			}
			else
			{
				current_y_corr = ((HEIGHT * y) / count_rows);
				while (current_y_corr < ((HEIGHT * (y + 1)) / count_rows))
				{
					current_x_corr = ((WIDTH * x) / ((int) ft_strlen(player->map->map[y]) - 1));
					while (current_x_corr < ((WIDTH * (x + 1)) / ((int) ft_strlen(player->map->map[y]) - 1)))
					{
						mlx_pixel_put(player->vars->mlx, player->vars->win, current_x_corr, current_y_corr, 0x000000);
						current_x_corr ++;
					}
					current_y_corr ++;
				}
			}
			current_y_corr = ((HEIGHT * y) / count_rows);
			while (current_y_corr <= ((HEIGHT * (y + 1)) / count_rows))
			{
				current_x_corr = ((WIDTH * x) / ((int) ft_strlen(player->map->map[y]) - 1));
				while (current_x_corr < ((WIDTH * (x + 1)) / ((int) ft_strlen(player->map->map[y]) - 1)))
				{
					if ((current_y_corr == ((HEIGHT * y) / count_rows)) || (current_y_corr == ((HEIGHT * (y + 1)) / (count_rows - 1))) \
					|| (current_x_corr == ((WIDTH * x) / ((int) ft_strlen(player->map->map[y]) - 1))) \
					|| current_x_corr == ((WIDTH * (x + 1)) / ((int) ft_strlen(player->map->map[y]) - 1)) - 1)
					{
						mlx_pixel_put(player->vars->mlx, player->vars->win, current_x_corr, current_y_corr, 0xFF0000);
					}
					current_x_corr ++;
				}
				current_y_corr ++;
			}
			x ++;
		}
		y ++;
	}
	return (0);
}

void	move_up(t_player *player)
{
	int ray_p = 25;
	int xrp;
	int yrp;

	player->y_player -= player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
//	while (--ray_p)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
//		xrp += cos(convert_to_radians(player->current_angle)) * 2;
//		yrp += sin(convert_to_radians(player->current_angle)) * 2;
//	}
}

void	move_down(t_player *player)
{
	int ray_p = 25;
	int xrp;
	int yrp;

	player->y_player += player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
//	while (--ray_p)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
//		xrp += cos(convert_to_radians(player->current_angle)) * 2;
//		yrp += sin(convert_to_radians(player->current_angle)) * 2;
//	}
}

void	move_right(t_player *player)
{
	int ray_p = 25;
	int xrp;
	int yrp;

	player->x_player += player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
//	while (--ray_p)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
//		xrp += cos(convert_to_radians(player->current_angle)) * 2;
//		yrp += sin(convert_to_radians(player->current_angle)) * 2;
//	}
}

void	move_left(t_player *player)
{
	int ray_p = 25;
	int xrp;
	int yrp;

	player->x_player -= player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
//	while (--ray_p)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
//		xrp += cos(convert_to_radians(player->current_angle)) * 2;
//		yrp += sin(convert_to_radians(player->current_angle)) * 2;
//	}
}

void	positive_rotatation(t_player *player)
{
	int ray_p = 25;
	int xrp;
	int yrp;

	player->current_angle -= 9;
	xrp = player->x_player;
	yrp = player->y_player;
//	while (--ray_p)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
//		xrp += cos(convert_to_radians(player->current_angle)) * 2;
//		yrp += sin(convert_to_radians(player->current_angle)) * 2;
//	}
}

void	negative_rotatation(t_player *player)
{
	int ray_p = 25;
	int xrp;
	int yrp;

	player->current_angle += 9;
	xrp = player->x_player;
	yrp = player->y_player;
//	while (--ray_p)
//	{
//		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
//		xrp += cos(convert_to_radians(player->current_angle)) * 2;
//		yrp += sin(convert_to_radians(player->current_angle)) * 2;
//	}
}

int player_key_hook(int keycode, t_player *player)
{
	if (keycode == A_KEY || keycode == D_KEY || keycode == W_KEY || keycode == S_KEY \
	|| keycode == RIGHT_ARROW_KEY || keycode == LEFT_ARROW_KEY)
	{
		render_map(player);
		if (keycode == A_KEY || keycode == D_KEY || keycode == W_KEY || keycode == S_KEY)
		{
			if (keycode == A_KEY)
				move_left(player);
			if (keycode == D_KEY)
				move_right(player);
			if (keycode == W_KEY)
				move_up(player);
			if (keycode == S_KEY)
				move_down(player);
		}
		else
		{
			if (keycode == RIGHT_ARROW_KEY)
				positive_rotatation(player);
			else
				negative_rotatation(player);
		}
	}
	return (0);
}

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	spawn_player(t_map *map_struct, t_vars *vars, t_player *player) {
	int x;
	int y;
	int yp;
	int xp;
	int ray_p;
	int count_rows;

	count_rows = count_map(map_struct->map);
	ray_p = 25;
	y = 0;
	while (map_struct->map[y])
	{
		x = 0;
		while (map_struct->map[y][x])
		{
			if (map_struct->map[y][x] == 'N' || map_struct->map[y][x] == 'S' || map_struct->map[y][x] == 'E' || map_struct->map[y][x] == 'W')
			{
				yp = (((HEIGHT * y) / count_rows) + (HEIGHT * (y + 1) / count_rows)) / 2;
				xp = (((WIDTH * x) / ((int) ft_strlen(map_struct->map[y]) - 1)) + ((WIDTH * (x + 1)) / ((int) ft_strlen(map_struct->map[y]) - 1))) / 2;
				player->x_player = xp;
				player->y_player = yp;
//				while (--ray_p)
//				{
//					mlx_pixel_put(vars->mlx, vars->win, xp, yp, 0x0000FF);
//					xp += cos(convert_to_radians(player->current_angle));
//					yp += sin(convert_to_radians(player->current_angle));
//				}
//				draw_ray(player);
			}
			x ++;
		}
		y ++;
	}
}

void	setup_screen(t_map *map_struct)
{
	t_vars	vars;
	t_player player;

	if (map_struct->player == 'N')
		player.current_angle = -90;
	if (map_struct->player == 'S')
		player.current_angle = 90;
	if (map_struct->player == 'E')
		player.current_angle = 180;
	if (map_struct->player == 'W')
		player.current_angle = 0;
	player.map = map_struct;
	player.vars = &vars;
	player.speed = 5;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return;
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "NEW DOOM");
	if (!vars.win)
		return;
	render_map(&player);
	spawn_player(map_struct, &vars, &player);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	mlx_key_hook(player.vars->win, player_key_hook, &player);
	mlx_loop_hook(vars.mlx, draw_ray, &player);
	mlx_loop(vars.mlx);
}

int	main(int argc, const char *argv[])
{
	char		**map;
	t_map		*map_struct;
	int			fd;

	map = NULL;
	map_struct = NULL;
	if (argc == 2)
	{
		fd = open_file(argv[1]);
		if (fd < 0)
			return (printf(RED"Error\n"RESET), 0);
//		if (!check_extension(argv[1]))
//			return (printf(RED"Error\n"RESET), 0);
		map = read_map(argv[1]);
		if (check_valid_map(map))
		{
			set_struct_parsing_map(&map_struct, map);
			setup_screen(map_struct);
		}
		else
			printf(RED"Error\n"RESET);
		close(fd);
	}
	else
		return (printf(RED"Error\n"RESET), 0);
	return (0);
}
