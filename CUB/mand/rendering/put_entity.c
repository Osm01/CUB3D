/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:12:46 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/17 10:41:35 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_ground(t_game_play *game, int start_x, int start_y,
		int WallHeigth)
{
	int	ground_start;

	ground_start = start_y + WallHeigth;
	while (ground_start < WINDOWS_HEIGHT)
	{
		if (ground_start >= 0 && ground_start <= WINDOWS_HEIGHT)
		{
			my_mlx_pixel_put(&game->img, start_x, ground_start,
				game->map.floor);
		}
		ground_start++;
	}
}

void	ft_put_wall(t_game_play *game, int start_x, int start_y,
		int wall_height)
{
	int					end_y;
	int					index;
	int					y;
	t_calcul_texture	calc;

	determine_texture(game, &calc.tex);
	end_y = start_y + wall_height;
	if (game->rays.hit_horizontal)
		calc.offset_x = (((float)calc.tex.width / TILE_SIZE)
				* (game->rays.wall_x % TILE_SIZE));
	else
		calc.offset_x = (((float)calc.tex.width / TILE_SIZE)
				* (game->rays.wall_y % TILE_SIZE));
	calc.scaler = ((float)calc.tex.height / wall_height);
	calc.column_offset = start_y;
	if (start_y < 0)
		calc.column_offset = 0;
	while (calc.column_offset < end_y && calc.column_offset < WINDOWS_HEIGHT)
	{
		y = ((calc.column_offset - start_y) * calc.scaler);
		index = (y * calc.tex.texture.line_length) + (calc.offset_x)
			* (calc.tex.texture.bits_per_pixel / 8);
		my_mlx_pixel_put(&game->img, start_x, calc.column_offset++,
			get_color(calc.tex, index));
	}
}

void	ft_put_sky(t_game_play *game, int start_x, int start_y)
{
	int	sky_start;
	int	sky_end;

	sky_start = 0;
	sky_end = start_y;
	while (sky_start < sky_end)
	{
		if (sky_start >= 0 && sky_start <= WINDOWS_HEIGHT)
		{
			my_mlx_pixel_put(&game->img, start_x, sky_start, game->map.ciel);
		}
		sky_start++;
	}
}

void	ft_put_cub(t_game_play *game, int start_x, int start_y, int WallHeigth)
{
	ft_put_sky(game, start_x, start_y);
	ft_put_wall(game, start_x, start_y, WallHeigth);
	ft_put_ground(game, start_x, start_y, WallHeigth);
}
