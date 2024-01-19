/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:09:21 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/12 10:05:27 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	determine_texture(t_game_play *game, t_texture1 *tex)
{
	if (sin(game->rays.ray_angle) >= 0 && game->rays.hit_horizontal)
	{
		tex->texture = game->texture.north_texture;
		tex->height = game->texture.tex_north_height;
		tex->width = game->texture.tex_north_width;
	}
	else if (sin(game->rays.ray_angle) <= 0 && game->rays.hit_horizontal)
	{
		tex->texture = game->texture.south_texture;
		tex->height = game->texture.tex_south_height;
		tex->width = game->texture.tex_south_width;
	}
	if (cos(game->rays.ray_angle) <= 0 && !game->rays.hit_horizontal)
	{
		tex->texture = game->texture.est_texture;
		tex->height = game->texture.tex_est_height;
		tex->width = game->texture.tex_est_width;
	}
	if (cos(game->rays.ray_angle) >= 0 && !game->rays.hit_horizontal)
	{
		tex->texture = game->texture.west_texture;
		tex->height = game->texture.tex_west_height;
		tex->width = game->texture.tex_west_width;
	}
}

unsigned int	get_color(t_texture1 tex, int index)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = tex.texture.addr[index];
	g = tex.texture.addr[index + 1];
	r = tex.texture.addr[index + 2];
	return (r << 16 | g << 8 | b);
}
