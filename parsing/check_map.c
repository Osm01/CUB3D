/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:09 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/13 16:12:19 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	check_dup_of_dir(char **map, int start)
{
	int	i;
	int	y;

	i = start;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W')
				return (1);
			y ++;
		}
		i ++;
	}
	return (0);
}

int	check_player_on_map(char **map)
{
	int	i;
	int	y;
	int	find_player;

	find_player = 0;
	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W')
			{
				find_player = 1;
				if (check_dup_of_dir(map, i + 1))
					return (0);
			}
		}
	}
	if (!find_player)
		return (0);
	return (1);
}

int	check_element_of_map(char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] != ' ' && map[i][y] != '0' && \
			map[i][y] != '1' && map[i][y] != '\n' && \
			!(map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W'))
				return (0);
		}
	}
	return (check_player_on_map(map));
}

int	count_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

int	check_valid_map(char **map)
{
	int		i;
	int		y;

	if (!map)
		return (0);
	if (!check_element_of_map(map))
		return (0);
	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == '0')
			{
				if (!i || !y || i == count_map(map) \
				|| (y == (int)ft_strlen(map[i]) - 2))
					return (0);
				if (map[i - 1][y] == ' ' || map[i + 1][y] == ' ' \
				|| map[i][y - 1] == ' ' || map[i][y + 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}
