/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:48:39 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/23 17:05:41 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//			if (map_struct->map[y][x] == 'N')
//			{
//				yp = (((HEIGHT * y) / count_rows) + (HEIGHT * (y + 1) / count_rows)) / 2;
//				xp = ((WIDTH * x) / ((int) ft_strlen(map_struct->map[y]) - 1)) + ((WIDTH * (x + 1)) / ((int) ft_strlen(map_struct->map[y]) - 1));
//				xp /= 2;
//				y_intercetion = yp - ((HEIGHT * y) / count_rows);
////				printf("PLAYER Y : %d , intercetion : %d\n", yp, y_intercetion);
////				exit(0);
//				while (1)
//				{
//					int z = y_intercetion;
//					while (z)
//					{
//						mlx_pixel_put(mlx_ptr, mlx_win, xp, yp --, 0xFF0000);
//						z --;
//					}
//				int yray = yp / (HEIGHT / count_rows) - 1;
//				int xray =  xp / (WIDTH / (int)ft_strlen(map_struct->map[yray])) - 1;
//				if (map_struct->map[yray][xray] == '1')
//					break ;
//				y_intercetion = HEIGHT / count_rows;
//				}
//			}

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

double	convert_to_radians(int value)
{
	return ((value * M_PI) / 180);
}

void	move_up(t_player *player)
{
	int ray_p = 50;
	int xrp;
	int yrp;

	player->y_player -= player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
	while (--ray_p)
	{
		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
		xrp += cos(convert_to_radians(player->current_angle)) * 2;
		yrp += sin(convert_to_radians(player->current_angle)) * 2;
	}
}

void	move_down(t_player *player)
{
	int ray_p = 50;
	int xrp;
	int yrp;

	player->y_player += player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
	while (--ray_p)
	{
		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
		xrp += cos(convert_to_radians(player->current_angle)) * 2;
		yrp += sin(convert_to_radians(player->current_angle)) * 2;
	}
}

void	move_right(t_player *player)
{
	int ray_p = 50;
	int xrp;
	int yrp;

	player->x_player += player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
	while (--ray_p)
	{
		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
		xrp += cos(convert_to_radians(player->current_angle)) * 2;
		yrp += sin(convert_to_radians(player->current_angle)) * 2;
	}
}

void	move_left(t_player *player)
{
	int ray_p = 50;
	int xrp;
	int yrp;

	player->x_player -= player->speed;
	xrp = player->x_player;
	yrp = player->y_player;
	while (--ray_p)
	{
		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
		xrp += cos(convert_to_radians(player->current_angle)) * 2;
		yrp += sin(convert_to_radians(player->current_angle)) * 2;
	}
}

void	positive_rotatation(t_player *player)
{
	int ray_p = 50;
	int xrp;
	int yrp;

	player->current_angle += 18;
	xrp = player->x_player;
	yrp = player->y_player;
	while (--ray_p)
	{
		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
		xrp += cos(convert_to_radians(player->current_angle)) * 2;
		yrp += sin(convert_to_radians(player->current_angle)) * 2;
	}
}

void	negative_rotatation(t_player *player)
{
	int ray_p = 50;
	int xrp;
	int yrp;

	player->current_angle -= 5;
	xrp = player->x_player;
	yrp = player->y_player;
	while (--ray_p)
	{
		mlx_pixel_put(player->vars->mlx, player->vars->win, xrp, yrp, 0x0000FF);
		xrp += cos(convert_to_radians(player->current_angle)) * 2;
		yrp += sin(convert_to_radians(player->current_angle)) * 2;
	}
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
	ray_p = 50;
	y = 0;
	while (map_struct->map[y])
	{
		x = 0;
		while (map_struct->map[y][x])
		{
			if (map_struct->map[y][x] == 'N')
			{
				yp = (((HEIGHT * y) / count_rows) + (HEIGHT * (y + 1) / count_rows)) / 2;
				xp = (((WIDTH * x) / ((int) ft_strlen(map_struct->map[y]) - 1)) + ((WIDTH * (x + 1)) / ((int) ft_strlen(map_struct->map[y]) - 1))) / 2;
				player->x_player = xp;
				player->y_player = yp;
				while (--ray_p)
				{
					mlx_pixel_put(vars->mlx, vars->win, xp, yp, 0x0000FF);
					xp += cos(convert_to_radians(player->current_angle));
					yp += sin(convert_to_radians(player->current_angle));
				}
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
//	int 	current_x_corr;
//	int 	current_y_corr;
//	int 	x;
//	int 	y;
//	int		count_rows;

	player.map = map_struct;
	player.vars = &vars;
	player.speed = 5;
	player.current_angle = 90;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return;
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "NEW DOOM");
	if (!vars.win)
		return;
//	y = 0;
//	count_rows = count_map(map_struct->map);
//	while (map_struct->map[y])
//	{
//		x = 0;
//		while (map_struct->map[y][x])
//		{
//			if (map_struct->map[y][x] == '1')
//			{
//				current_y_corr = ((HEIGHT * y) / count_rows);
//				while (current_y_corr < ((HEIGHT * (y + 1)) / count_rows))
//				{
//					current_x_corr = ((WIDTH * x) / ((int) ft_strlen(map_struct->map[y]) - 1));
//					while (current_x_corr < ((WIDTH * (x + 1)) / ((int) ft_strlen(map_struct->map[y]) - 1)))
//					{
//						mlx_pixel_put(vars.mlx, vars.win, current_x_corr, current_y_corr, 0xFFFFFF);
//						current_x_corr ++;
//					}
//					current_y_corr ++;
//				}
//			}
//			current_y_corr = ((HEIGHT * y) / count_rows);
//			while (current_y_corr <= ((HEIGHT * (y + 1)) / count_rows))
//			{
//				current_x_corr = ((WIDTH * x) / ((int) ft_strlen(map_struct->map[y]) - 1));
//				while (current_x_corr < ((WIDTH * (x + 1)) / ((int) ft_strlen(map_struct->map[y]) - 1)))
//				{
//					if ((current_y_corr == ((HEIGHT * y) / count_rows)) || (current_y_corr == ((HEIGHT * (y + 1)) / (count_rows - 1))) \
//					|| (current_x_corr == ((WIDTH * x) / ((int) ft_strlen(map_struct->map[y]) - 1))) \
//					|| current_x_corr == ((WIDTH * (x + 1)) / ((int) ft_strlen(map_struct->map[y]) - 1)) - 1)
//					{
//						mlx_pixel_put(vars.mlx, vars.win, current_x_corr, current_y_corr, 0xFF0000);
//					}
//					current_x_corr ++;
//				}
//				current_y_corr ++;
//			}
//			x ++;
//		}
//		y ++;
//	}
	render_map(&player);
	spawn_player(map_struct, &vars, &player);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	mlx_key_hook(player.vars->win, player_key_hook, &player);
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
