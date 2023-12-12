/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:10:40 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/12 14:16:19 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

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
		if (i >= 6 && !ft_strcmp(readline, "\n") && !count)
			count = 1;
		else if (count > 0)
			count ++;
		if (!ft_strcmp(readline, "\n"))
			i ++;
		free(readline);
	}
	if (i < 6 || fd < 0)
		return (-1);
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
		if (y <= 6)
			free(readline);
		else
		{
			if (!i && !ft_strcmp(readline, "\n"))
				map[i ++] = readline;
			else if (i)
				map[i ++] = readline;
		}
		y ++;
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
