/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:03:57 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:36 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_hit_wall(t_game_play *game_play, int pos_x, int pos_y)
{
	double	a;

	a = 0;
	while (a <= 2 * PI)
	{
		if (ft_collision(game_play, pos_x + (10) * cos(a),
				pos_y + (10) * sin(a)))
			return (1);
		a += PI / 2;
	}
	return (0);
}

void	move_it(t_game_play *game_play, double angle, int direction)
{
	int	nextx;
	int	nexty;

	nextx = (game_play->player.x) + roundf(game_play->player.move_speed
			* direction * cos(angle));
	nexty = (game_play->player.y) + roundf(game_play->player.move_speed
			* direction * sin(angle));
	if (is_hit_wall(game_play, nextx, nexty) == 0)
	{
		(game_play->player.x) = nextx;
		(game_play->player.y) = nexty;
		ft_draw_loop(game_play);
	}
}

void	move_player(void *param)
{
	t_game_play	*game_play;

	game_play = (t_game_play *)param;
	if (game_play->key_event.key_left)
		move_it(game_play, game_play->player.rot_angle - PI / 2, 1);
	else if (game_play->key_event.key_up)
		move_it(game_play, game_play->player.rot_angle, 1);
	else if (game_play->key_event.key_right)
		move_it(game_play, game_play->player.rot_angle + PI / 2, 1);
	else if (game_play->key_event.key_down)
		move_it(game_play, game_play->player.rot_angle, -1);
}

void	rotate_player(void *param)
{
	t_game_play	*game_play;

	game_play = (t_game_play *)param;
	mlx_clear_window(game_play->mlxxx.mlx, game_play->mlxxx.mlx_win);
	if (game_play->key_event.left_arrow)
	{
		(game_play->player.rot_angle) -= PI / 20;
		game_play->player.rot_angle = ft_angle(game_play->player.rot_angle);
		ft_draw_loop(game_play);
		mlx_put_image_to_window(game_play->mlxxx.mlx, game_play->mlxxx.mlx_win,
			game_play->img.img, 0, 0);
	}
	else if (game_play->key_event.right_arrow)
	{
		(game_play->player.rot_angle) += PI / 20;
		game_play->player.rot_angle = ft_angle(game_play->player.rot_angle);
		ft_draw_loop(game_play);
		mlx_put_image_to_window(game_play->mlxxx.mlx, game_play->mlxxx.mlx_win,
			game_play->img.img, 0, 0);
	}
}

int	close_window(t_game_play *game_play)
{
	(game_play) = NULL;
	return (exit(0), 0);
}
