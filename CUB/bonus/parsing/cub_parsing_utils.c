/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:44:32 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 14:45:36 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub_parsing.h"

void	print_and_exit(void)
{
	printf(RED1"Error\n"RESET);
	exit(1);
}

void	check_valid_map_norm(t_parsing *parsing, char **map)
{
	char	**square_map;

	square_map = NULL;
	set_struct_parsing_map(&parsing->map, map);
	removing_new_lines_end(parsing->map->map);
	set_floor_ceil(&parsing->floor_ciel, parsing->elements);
	square_map = set_square_map(parsing->map->map);
	parsing->map->map = square_map;
}

void	initiaize_struct(t_parsing *parsing)
{
	parsing->map = NULL;
	parsing->elements = NULL;
	parsing->floor_ciel = NULL;
}

void	is_not_valid_map_and_element(t_parsing *parsing, char **elements,
			char **map)
{
	if (elements)
		freeing_double_pointer(elements);
	if (map)
		freeing_double_pointer(map);
	freeing_parsing_struct(parsing);
	print_and_exit();
}

void	ft_check_map_and_elements(t_parsing *parsing, char **elements,
			char **map, int fd)
{
	if (check_valid_elements(elements, &parsing->elements))
	{
		if (check_valid_map(map))
			check_valid_map_norm(parsing, map);
		else
			is_not_valid_map_and_element(parsing, elements, map);
	}
	else
		is_not_valid_map_and_element(parsing, elements, map);
	close(fd);
	if (elements)
		freeing_double_pointer(elements);
	if (map)
		freeing_double_pointer(map);
}
