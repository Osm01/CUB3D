/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/18 14:44:49 by nbaghoug         ###   ########.fr       */
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
		if (ft_strcmp(elements_struct->key, "F")
			|| ft_strcmp(elements_struct->key, "C"))
			add_back_floor_ceil(floor_ciel,
				add_new_floor_ceil(elements_struct->key,
					elements_struct->value));
		elements_struct = elements_struct->next;
	}
}

t_parsing	parsing123(int argc, const char *argv[])
{
	char			**map;
	char			**elements;
	t_parsing		parsing;
	int				fd;

	map = NULL;
	elements = NULL;
	initiaize_struct(&parsing);
	if (argc == 2)
	{
		fd = open_file(argv[1]);
		if (fd < 0 || !check_extension(argv[1]))
			print_and_exit();
		elements = read_elements(argv[1]);
		map = read_map(argv[1]);
		ft_check_map_and_elements(&parsing, elements, map, fd);
	}
	else
		print_and_exit();
	return (parsing);
}
