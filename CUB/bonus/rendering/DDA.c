/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:38:15 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/14 14:11:49 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_initialize_for_x_intercept(t_DDA *dda, t_game_play *game,
		double rayAngle)
{
	dda->direction_flag = 0;
	dda->start_y = (game->player.y / TILE_SIZE) * TILE_SIZE;
	if (rayAngle > 0 && rayAngle < PI)
		dda->start_y += TILE_SIZE;
	else
		dda->direction_flag = -1;
	dda->start_x = game->player.x + (dda->start_y - game->player.y)
		/ tan(ft_angle(rayAngle));
	dda->dy = TILE_SIZE;
	dda->dx = (dda->dy / tan(ft_angle(rayAngle)));
	if (lookin_up(rayAngle))
		dda->dy *= -1;
	if (dda->dx < 0 && lookin_right(rayAngle))
		dda->dx *= -1;
	if (dda->dx > 0 && lookin_left(rayAngle))
		dda->dx *= -1;
}

t_coordonner	x_intercept(t_game_play *game, double rayAngle)
{
	t_coordonner	c;
	t_DDA			dda;
	float			x;
	float			y;

	ft_initialize_for_x_intercept(&dda, game, rayAngle);
	x = dda.start_x;
	y = dda.start_y;
	while ((x >= 0 && x < game->map.len_x) && (y >= 0 && y < game->map.len_y))
	{
		if (ft_collision(game, x, y + dda.direction_flag) == 0)
		{
			x += (dda.dx);
			y += (dda.dy);
		}
		else
			break ;
	}
	c.x = x;
	c.y = y;
	return (c);
}

void	ft_initialize_for_y_intercept(t_DDA *dda, t_game_play *game,
		double rayAngle)
{
	dda->direction_flag = 0;
	dda->start_x = (game->player.x / TILE_SIZE) * TILE_SIZE;
	if (lookin_right(rayAngle))
		dda->start_x += TILE_SIZE;
	else
		dda->direction_flag = -1;
	dda->start_y = ((game->player.y + (dda->start_x - game->player.x)
				* (tan(ft_angle(rayAngle)))));
	dda->dx = TILE_SIZE;
	dda->dy = (dda->dx * tan(ft_angle(rayAngle)));
	if (lookin_left(rayAngle))
		dda->dx *= -1;
	if (dda->dy < 0 && lookin_down(rayAngle))
		dda->dy *= -1;
	if (dda->dy > 0 && lookin_up(rayAngle))
		dda->dy *= -1;
}

t_coordonner	y_intercept(t_game_play *game, double rayAngle)
{
	t_coordonner	c;
	float			yv;
	float			xv;
	t_DDA			dda;

	ft_initialize_for_y_intercept(&dda, game, rayAngle);
	xv = dda.start_x;
	yv = dda.start_y;
	while ((xv >= 0 && xv < game->map.len_x) && (yv >= 0
			&& yv < game->map.len_y))
	{
		if (ft_collision(game, xv + dda.direction_flag, yv) == 0)
		{
			xv += (dda.dx);
			yv += (dda.dy);
		}
		else
			break ;
	}
	c.x = xv;
	c.y = yv;
	return (c);
}

t_rays	dda(t_game_play *game, double ray_angle)
{
	float			dx;
	float			dy;
	t_rays			rrr;
	t_coordonner	c;
	t_coordonner	d;

	c = x_intercept(game, ft_angle(ray_angle));
	d = y_intercept(game, ft_angle(ray_angle));
	dx = (sqrt((c.x - game->player.x) * (c.x - game->player.x) + (c.y
					- game->player.y) * (c.y - game->player.y)));
	dy = (sqrt((d.x - game->player.x) * (d.x - game->player.x) + (d.y
					- game->player.y) * (d.y - game->player.y)));
	if (dx < dy)
	{
		rrr.wall_x = roundf(c.x);
		rrr.hit_horizontal = 1;
	}
	else
	{
		rrr.wall_y = roundf(d.y);
		rrr.hit_horizontal = 0;
	}
	rrr.distance_to_wall = (fmin(dx, dy));
	return (rrr);
}
