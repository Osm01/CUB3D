/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/16 16:48:49 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

char	**read_elements(const char *file_name)
{
	char	**map_elements;
	char	*read_line;
	int		fd;
	int		i;

	fd = open_file(file_name);
	map_elements = (char **) malloc(sizeof (char *) * (6 + 1));
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
		else
			free(read_line);
	}
	map_elements[i] = NULL;
	return (close(fd), map_elements);
}

void	set_struct_parsing_map(t_map **map_struct, char **map)
{
	*map_struct = (t_map *) malloc(sizeof (t_map));
	(*map_struct)->player = player_dir(map);
	(*map_struct)->map = map;
}

void	set_floor_ceil(t_floor_ciel **floor_ciel, t_elements *elements_struct)
{
	while (elements_struct)
	{
		if (ft_strcmp(elements_struct->key, "F") || ft_strcmp(elements_struct->key, "C"))
			add_back_floor_ceil(floor_ciel, add_new_floor_ceil(elements_struct->key, elements_struct->value));
		elements_struct = elements_struct->next;
	}
}

int	main(int argc, const char *argv[])
{
	char			**map;
	char			**elements;
	t_parsing		parsing;
	char			**square_map;
	int				fd;

	map = NULL;
	elements = NULL;
	parsing.map = NULL;
	parsing.elements = NULL;
	parsing.floor_ciel = NULL;
	square_map = NULL;
	if (argc == 2)
	{
		fd = open_file(argv[1]);
		if (fd < 0)
			return (printf(RED"Error\n"RESET), 0);
		if (!check_extension(argv[1]))
			return (printf(RED"Error\n"RESET), 0);
		elements = read_elements(argv[1]);
		map = read_map(argv[1]);
		if (check_valid_elements(elements, &parsing.elements))
		{
			if (check_valid_map(map))
			{
				set_struct_parsing_map(&parsing.map, map);
				removing_new_lines_end(parsing.map->map);
				set_floor_ceil(&parsing.floor_ciel, parsing.elements);
				square_map = set_square_map(parsing.map->map);
				parsing.map->map = square_map;
			}
			else
				printf(RED"Error\n"RESET);
		}
		else
			printf(RED"Error\n"RESET);
		close(fd);
		if (elements)
			freeing_double_pointer(elements);
		if (map)
			freeing_double_pointer(map);
		freeing_parsing_struct(&parsing);
	}
	else
		return (printf(RED"Error\n"RESET), 0);
	return (0);
}
