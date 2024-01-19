/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:04:26 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 18:44:45 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rendering/cub3D.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	ft_angle(double angle)
{
	while (angle > 2 * PI)
		angle -= 2 * PI;
	while (angle < 0)
		angle += 2 * PI;
	return (angle);
}

int	key_pressed1(int keycode, void *param)
{
	t_game_play	*game;

	game = (t_game_play *)param;
	if (keycode == MOVE_LEFT)
		game->key_event.key_left = 1;
	if (keycode == MOVE_RIGHT)
		game->key_event.key_right = 1;
	if (keycode == MOVE_UP)
		game->key_event.key_up = 1;
	if (keycode == MOVE_DOWN)
		game->key_event.key_down = 1;
	if (keycode == TURN_LEFT)
		game->key_event.left_arrow = 1;
	if (keycode == TURN_RIGHT)
		game->key_event.right_arrow = 1;
	if (keycode == ESC)
		game->key_event.esc = 1;
	if (keycode == 49 && game->animation->index == 0)
	{
		game->animation->index = 1;
		game->animation->timer = 0;
		game->animation->start_frames = 1;
	}
	return (0);
}

int	key_realsed(int keycode, void *param)
{
	t_game_play	*game;

	game = (t_game_play *)param;
	if (keycode == MOVE_LEFT)
		game->key_event.key_left = 0;
	if (keycode == MOVE_RIGHT)
	{
		game->key_event.key_right = 0;
	}
	if (keycode == MOVE_UP)
	{
		game->key_event.key_up = 0;
	}
	if (keycode == MOVE_DOWN)
	{
		game->key_event.key_down = 0;
	}
	if (keycode == TURN_LEFT)
		game->key_event.left_arrow = 0;
	if (keycode == TURN_RIGHT)
		game->key_event.right_arrow = 0;
	if (keycode == ESC)
		game->key_event.esc = 1;
	return (0);
}

char	**dup_map(char **map)
{
	char	**dmap;
	int		i;
	int		j;
	int		x;
	int		y;

	lenx_leny_of_map(map, &x, &y);
	x = x / TILE_SIZE;
	y = y / TILE_SIZE;
	dmap = malloc(sizeof(char *) * (y + 1));
	dmap[y] = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		dmap[i] = malloc(sizeof(char) * (x + 1));
		while (map[i][j])
		{
			dmap[i][j] = map[i][j];
			j++;
		}
		dmap[i][j] = 0;
		i++;
	}
	return (dmap);
}
