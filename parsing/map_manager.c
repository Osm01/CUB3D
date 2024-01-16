/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:10:40 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/18 15:11:49 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

char	player_dir(char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == 'N' || map[i][y] == 'S' \
			|| map[i][y] == 'E' || map[i][y] == 'W')
				return (map[i][y]);
		}
	}
	return ('0');
}

int	count_line_of_map(const char *file_name)
{
	char	*readline;
	int		count;
	int		fd;
	int		i;

	count = 0;
	i = 0;
	fd = open_file(file_name);
	while (1)
	{
		readline = get_next_line(fd);
		if (!readline)
			break ;
		if (i >= 6 && !ft_strcmp(readline, "\n"))
			count ++;
		if (count && ft_strcmp(readline, "\n"))
			return (close(fd), free(readline), -1);
		if (!ft_strcmp(readline, "\n"))
			i ++;
		free(readline);
	}
	if (i < 6 || fd < 0)
		count = -1;
	return (close(fd), count);
}

void	set_map(char **map, int fd, int count)
{
	char	*readline;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < count)
	{
		readline = get_next_line(fd);
		if (!readline)
			break ;
		if (!ft_strcmp(readline, "\n"))
			y ++;
		if (y <= 6)
			free(readline);
		else
		{
			if (!i && !ft_strcmp(readline, "\n"))
				map[i ++] = readline;
			else if (i)
				map[i ++] = readline;
			else
				free(readline);
		}
	}
	map[count] = NULL;
}

char	**read_map(const char *file_name)
{
	char	**map;
	int		fd;
	int		count;

	fd = open_file(file_name);
	count = count_line_of_map(file_name);
	if (fd < 0)
		return (NULL);
	if (count <= 0)
		return (close(fd), NULL);
	map = (char **) malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (close(fd), NULL);
	set_map(map, fd, count);
	return (close(fd), map);
}
