/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:20:58 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/17 12:25:38 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(t_img *img, double angle)
{
	int		i;
	double	a;

	i = 0;
	a = 0;
	while (i < 40)
	{
		my_mlx_pixel_put(img, 100 + i * cos(angle), 100 + i * sin(angle), RED);
		i++;
	}
}

void	ft_draw_player(t_img *img, int color)
{
	int		i;
	int		j;
	double	a;

	i = 0;
	j = 0;
	a = 0;
	while (a < 2 * PI)
	{
		i = 0;
		j = 0;
		while (i < 10)
		{
			my_mlx_pixel_put(img, 100 + i * cos(a),
				100 + j * sin(a), color);
			i++;
			j++;
		}
		a += 0.1;
	}
}
