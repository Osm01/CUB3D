/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:42:37 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 16:06:28 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	lenx_leny_of_map(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	*y = i * TILE_SIZE;
	*x = j * TILE_SIZE;
}

void	initialize_colors(t_game_play *game_play, t_parsing *parsing1)
{
	struct s_floor_ciel	*tmp;

	tmp = parsing1->floor_ciel;
	if (tmp->key == 'F')
		game_play->map.floor = tmp->value;
	else
		game_play->map.ciel = tmp->value;
	if (tmp->next->key == 'F')
		game_play->map.floor = tmp->next->value;
	else
		game_play->map.ciel = tmp->next->value;
}

void	initialize_game_play(t_game_play *game_play, t_parsing *parsing1)
{
	game_play->mlxxx.mlx = mlx_init();
	if (!game_play->mlxxx.mlx)
	{
		exit(0);
	}
	game_play->mlxxx.mlx_win = mlx_new_window(game_play->mlxxx.mlx,
			WINDOWS_WIDTH,
			WINDOWS_HEIGHT,
			"cub3D");
	player_position(parsing1->map->map, &game_play->player.x,
		&game_play->player.y);
	game_play->player.move_speed = 5;
	game_play->player.rot_angle = HALF_PI;
	game_play->map.map = parsing1->map->map;
	start_direction(game_play);
	initialize_colors(game_play, parsing1);
	lenx_leny_of_map(game_play->map.map, &(game_play->map.len_x),
		&(game_play->map.len_y));
	initialize_text_north(game_play, parsing1);
	initialize_text_south(game_play, parsing1);
	initialize_text_west(game_play, parsing1);
	initialize_text_east(game_play, parsing1);
	initialize_event_key(game_play);
}

void	start_direction(t_game_play *game_play)
{
	if (game_play->map.map[game_play->player.y / TILE_SIZE][game_play->player.x
		/ TILE_SIZE] == 'N')
		game_play->player.rot_angle = -HALF_PI;
	else if (game_play->map.map[game_play->player.y
			/ TILE_SIZE][game_play->player.x / TILE_SIZE] == 'S')
		game_play->player.rot_angle = HALF_PI;
	else if (game_play->map.map[game_play->player.y
			/ TILE_SIZE][game_play->player.x / TILE_SIZE] == 'E')
		game_play->player.rot_angle = 0;
	else if (game_play->map.map[game_play->player.y
			/ TILE_SIZE][game_play->player.x / TILE_SIZE] == 'W')
		game_play->player.rot_angle = PI;
}
