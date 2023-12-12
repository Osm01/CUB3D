/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:24:09 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/12 16:11:15 by ouidriss         ###   ########.fr       */
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

int	check_valid_map(char const *filename)
{
	char	**map;
	int		i;
	int		y;

	i = -1;
	map = read_map(filename);
	if (!map)
		return (0);
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W')
			{
				if (check_dup_of_dir(map, i + 1))
					return (0);
			}
			else if (map[i][y] != ' ' && map[i][y] != '0' && \
			map[i][y] != '1' && map[i][y] != '\n')
				return (0);
		}
	}
	return (1);
}

int check_player_on_map(char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == '0')
			{
				if (!(map[i - 1][y] == '1' && map[i + 1][y] == '1' \
				&& map[i][y - 1] == '1' && map[i][y + 1] == '1'))
					return (0);
			}
			if (map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W')
			{
				if (!(map[i - 1][y] == '1' && map[i + 1][y] == '1' \
				&& map[i][y - 1] == '1' && map[i][y + 1] == '1'))
					return (0);
			}
		}
	}
}
