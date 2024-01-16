/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_addictional.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:01:55 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/16 15:12:08 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	check_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (ft_strlen(line) - i);
		i ++;
	}
	return (0);
}

int	check_element_0(char **map, int x_index, int y_index)
{
	int	i;
	int	y;

	i = x_index;
	y = y_index;
	if (!i || (i == count_map(map) - 1))
		return (0);
	if (y > (int)ft_strlen(map[i - 1]) - 2 || \
	y > ((int)ft_strlen(map[i + 1]) - check_new_line(map[i + 1]) - 1))
		return (0);
	if (map[i][y + 1] == ' ' || map[i][y - 1] == ' ' \
	|| map[i + 1][y] == ' ' || map[i - 1][y] == ' ')
		return (0);
	return (1);
}

int	check_first_and_last(char **map, int i)
{
	if (map[i][index_first_element_of_map(map[i])] != '1')
		return (0);
	if (map[i][(int)ft_strlen(map[i]) - 1] == '\n')
	{
		if (map[i][(int)ft_strlen(map[i]) - 2] != '1')
			return (0);
	}
	else
	{
		if (map[i][(int)ft_strlen(map[i]) - 1] != '1')
			return (0);
	}
	return (1);
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
			if (map[i][y] == '0' && !check_element_0(map, i, y))
				return (0);
		}
		if (!check_first_and_last(map, i))
			return (0);
	}
	return (1);
}

void	removing_new_lines_end(char **map)
{
	int	i;
	int	y;

	i = 0;
	while (map[i])
	{
		y = ft_strlen(map[i]);
		if (map[i][y - 1] == '\n')
			map[i][y - 1] = 0;
		i ++;
	}
}
