/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:38:25 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 14:01:35 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	right_rotation(t_game_play *game_play)
{
	(game_play->player.rot_angle) += PI / 10;
	game_play->player.rot_angle = ft_angle(game_play->player.rot_angle);
	ft_draw_loop(game_play);
	mlx_put_image_to_window(game_play->mlxxx.mlx,
		game_play->mlxxx.mlx_win,
		game_play->img.img,
		0,
		0);
}

void	left_rotation(t_game_play *game_play)
{
	(game_play->player.rot_angle) -= PI / 10;
	game_play->player.rot_angle = ft_angle(game_play->player.rot_angle);
	ft_draw_loop(game_play);
	mlx_put_image_to_window(game_play->mlxxx.mlx,
		game_play->mlxxx.mlx_win,
		game_play->img.img,
		0,
		0);
}
