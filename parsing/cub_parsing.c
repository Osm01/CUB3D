/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/13 18:16:39 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

const char	**read_elements(const char *file_name)
{
	const char	**map_elements;
	char		*read_line;
	int			fd;
	int			i;

	fd = open_file(file_name);
	if (fd < 0)
		return (NULL);
	map_elements = (const char **) malloc(sizeof (char *) * (6 + 1));
	if (!map_elements)
		return (close(fd), NULL);
	i = 0;
	while (1)
	{
		if (i >= 6)
			break ;
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		if (!ft_strcmp(read_line, "\n"))
			map_elements[i ++] = read_line;
	}
	map_elements[i] = NULL;
	return (close(fd), map_elements);
}

int	main(int argc, const char *argv[])
{
	char		**map;
	t_map		map_struct;

	t_elem = NULL;
	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			return (printf(RED"Error\n"RESET), 0);
		map = read_map(argv[1]);
		if (check_valid_map(map))
		{
			map_struct = malloc(sizeof (t_map));
			map_struct.map = map;
			map_struct.player = player_dir(map);
		}
		else
			printf(RED"NOT VALID"RESET);
	}
	else
		return (printf(RED"Error\n"RESET), 0);
	return (0);
}
