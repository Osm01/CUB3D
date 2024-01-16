/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/19 18:12:59 by ouidriss         ###   ########.fr       */
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
				set_struct_parsing_map(&parsing.map, map);
			else
				return (printf(RED"Error\n"RESET), /*free_elements(&parsing.elements),*/0);
		}
		else
			return (printf(RED"Error\n"RESET), /*freeing_double_pointer(elements),\
			freeing_double_pointer(elements),*/ 0);
		close(fd);
		removing_new_lines_end(parsing.map->map);
		set_floor_ceil(&parsing.floor_ciel, parsing.elements);
		square_map = set_square_map(parsing.map->map);
		int i = 0;
		while (square_map[i])
			printf("-%s-\n", square_map[i ++]);
//		freeing_parsing_struct(&parsing);
	}
	else
		return (printf(RED"Error\n"RESET), 0);
	return (0);
}


//int	main(int argc, const char *argv[])
//{
//	char		**map;
//	t_map		*map_struct;
//	int			fd;
//
//	map = NULL;
//	map_struct = NULL;
//	if (argc == 2)
//	{
//		fd = open_file(argv[1]);
//		if (fd < 0)
//			return (printf(RED"Error\n"RESET), 0);
//		if (!check_extension(argv[1]))
//			return (printf(RED"Error\n"RESET), 0);
//		printf("HERE\n");
//		map = read_map(argv[1]);
//		if (check_valid_map(map))
//		{
//			set_struct_parsing_map(&map_struct, map);
//		}
//		else
//			printf(RED"Error\n"RESET);
//		close(fd);
//	}
//	else
//		return (printf(RED"Error\n"RESET), 0);
//	return (0);
//}



//  ------------- testing ----------------
//while (parsing.elements)
//{
//printf("key : %s and value : %s\n", parsing.elements->key, parsing.elements->value);
//parsing.elements = parsing.elements->next;
//}
//while (parsing.floor_ciel)
//{
//printf("(%c => %u)\n", parsing.floor_ciel->key, parsing.floor_ciel->value);
//parsing.floor_ciel = parsing.floor_ciel->next;
//}
//if (parsing.map)
//{
//int i = 0;
//while (parsing.map->map[i])
//printf("%s\n", parsing.map->map[i ++]);
//printf("Player : %c\n",parsing.map->player);
//}


// ------------------------------------------------------ //

//		removing_new_lines_end(parsing.map->map);
//		set_floor_ceil(&parsing.floor_ciel, parsing.elements);
//		square_map = set_square_map(parsing.map->map);
//		int i = 0;
//		while (parsing.map->map[i])
//			free(parsing.map->map[i++]);
//		free(parsing.map->map);
//		parsing.map->map = square_map;
//		i = 0;
//		while (parsing.map->map[i])
//			printf("-%s-\n", parsing.map->map[i ++]);
//		int i = 0;
//		while (map[i])

//		int i = 0;
//		if (elements)
//		{
//			while (elements[i])
//				free(elements[i ++]);
//			free(elements);
//		}
//		i = 0;
//		if (map)
//		{
//			while (map[i])
//				free(map[i ++]);
//			free(map);
//		}
//		if (map_struct)
//			free(map_struct);
//		t_elements *tmp;
//		if (elements_struct)
//		{
//			while (elements_struct)
//			{
//				tmp = elements_struct;
//				elements_struct = elements_struct->next;
//				free(tmp->key);
//				free(tmp->value);
//				free(tmp);
//			}
//		}