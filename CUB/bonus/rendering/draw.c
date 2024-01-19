/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:10:27 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/17 13:12:47 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_walls(t_game_play *game)
{
	int		nbrofrays;
	int		i;
	double	ray_angle;
	int		wallheight;

	nbrofrays = WINDOWS_WIDTH;
	i = 0;
	ray_angle = (game->player.rot_angle) - FOV / 2;
	while (i < nbrofrays)
	{
		game->rays = dda(game, ft_angle(ray_angle));
		game->rays.ray_angle = ft_angle(ray_angle);
		game->rays.distance_to_wall *= cos(ft_angle(game->player.rot_angle
					- ray_angle));
		ray_angle += FOV / nbrofrays;
		wallheight = ((TILE_SIZE / (game->rays.distance_to_wall))
				* ((WINDOWS_WIDTH / 2) / tan(FOV / 2)));
		ft_put_cub(game, i, (WINDOWS_HEIGHT / 2)
			- (wallheight / 2), (wallheight));
		i++;
	}
}

int	ft_check_1(t_game_play *game_play, float tile_x, float tile_y)
{
	if (tile_x >= 0 && tile_y >= 0
		&& tile_x < game_play->map.len_x / TILE_SIZE
		&& tile_y < game_play->map.len_y / TILE_SIZE)
		return (1);
	return (0);
}

int	ft_check_2(t_game_play *game_play, float tile_x, float tile_y)
{
	if (game_play->map.map[(int)tile_y][(int)tile_x] == '0'
		|| game_play->map.map[(int)tile_y][(int)tile_x] == 'N'
		|| game_play->map.map[(int)tile_y][(int)tile_x] == 'S'
		|| game_play->map.map[(int)tile_y][(int)tile_x] == 'W'
		|| game_play->map.map[(int)tile_y][(int)tile_x] == 'E')
		return (1);
	return (0);
}

void	ft_draw2(t_game_play *game_play, float start_x, float start_y)
{
	float	tile_x;
	float	tile_y;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 200)
	{
		y = 0;
		tile_x = (x + start_x) / TILE_SIZE;
		while (y < 200)
		{
			tile_y = (y + start_y) / TILE_SIZE;
			if (ft_check_1(game_play, tile_x, tile_y))
			{
				if (ft_check_2(game_play, tile_x, tile_y))
					my_mlx_pixel_put(&game_play->img, x, y, WHITE);
				else
					my_mlx_pixel_put(&game_play->img, x, y, BLACK);
			}
			y++;
		}
		x++;
	}
}

void	ft_draw_loop(t_game_play *game_play)
{
	int		x;
	int		y;
	float	start_x;
	float	start_y;

	x = 0;
	y = 0;
	draw_walls(game_play);
	start_x = game_play->player.x - 100;
	start_y = game_play->player.y - 100;
	ft_draw2(game_play, start_x, start_y);
	ft_draw_player(&game_play->img, RED);
	draw_line(&game_play->img, game_play->player.rot_angle);
}
