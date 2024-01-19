/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:01:53 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/15 14:02:22 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	find_long_line(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = ft_strlen(map[0]);
	while (map[i])
	{
		if (count < (int)ft_strlen(map[i]))
			count = ft_strlen(map[i]);
		i ++;
	}
	return (count);
}

int	nb_rows_of_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i ++;
	return (i);
}

char	**alloc_to_fill_square_map(char **map)
{
	char	**new_map;
	int		i;
	int		count;
	int		nb_rows;

	nb_rows = nb_rows_of_map(map);
	count = find_long_line(map);
	new_map = (char **)malloc(sizeof (char *) * (nb_rows + 1));
	if (!new_map)
		return (NULL);
	i = -1;
	while (++i < nb_rows)
	{
		new_map[i] = malloc(sizeof (char) * (count + 1));
		if (!new_map[i])
			return (NULL);
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**set_square_map(char **map)
{
	char	**square_map;
	int		nb_rows;
	int		long_line;
	int		i;
	int		y;

	square_map = alloc_to_fill_square_map(map);
	if (!square_map)
		return (NULL);
	nb_rows = nb_rows_of_map(map);
	long_line = find_long_line(map);
	i = 0;
	while (i < nb_rows)
	{
		y = -1;
		while (map[i][++y])
			square_map[i][y] = map[i][y];
		while (y < long_line)
			square_map[i][y ++] = ' ';
		square_map[i][y] = 0;
		i ++;
	}
	return (square_map);
}
