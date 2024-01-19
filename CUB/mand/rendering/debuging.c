/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuging.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:46:04 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/17 13:30:18 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_map(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		fprintf(stderr, "%s\n", p[i]);
		i++;
	}
}

t_rays	*ft_get_rays(t_game_play *game)
{
	int		nbr_of_rays;
	int		i;
	double	ray_angle;
	t_rays	*drays;

	nbr_of_rays = WINDOWS_WIDTH;
	i = 0;
	drays = malloc(nbr_of_rays * sizeof(t_rays));
	ray_angle = (game->player.rot_angle) - FOV / 2;
	ray_angle = ft_angle(ray_angle);
	while (i < nbr_of_rays)
	{
		drays[i] = dda(game, ft_angle(ray_angle));
		drays[i].ray_angle = ft_angle(ray_angle);
		ray_angle += FOV / nbr_of_rays;
		i++;
	}
	return (drays);
}

void	initialize_event_key(t_game_play *game_play)
{
	game_play->key_event.key_up = 0;
	game_play->key_event.key_down = 0;
	game_play->key_event.key_left = 0;
	game_play->key_event.key_right = 0;
	game_play->key_event.left_arrow = 0;
	game_play->key_event.right_arrow = 0;
	game_play->key_event.esc = 0;
}

void	player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
			{
				*x = j * TILE_SIZE + 35;
				*y = i * TILE_SIZE + 35;
				return ;
			}
			j++;
		}
		i++;
	}
}
