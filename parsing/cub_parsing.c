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

void	freeing_double_pointer(char **ptr)
{
	int	i;

	if (ptr)
	{
		i = 0;
		while (ptr[i])
			free(ptr[i ++]);
		free(ptr);
	}
}


//int	main(int argc, const char *argv[])
//{
//	char		**map;
//	char		**elements;
//	t_map		*map_struct;
//	t_elements	*elements_struct;
//	int			fd;
//
//	map = NULL;
//	elements = NULL;
//	map_struct = NULL;
//	elements_struct = NULL;
//	if (argc == 2)
//	{
//		fd = open_file(argv[1]);
//		if (fd < 0)
//			return (printf(RED"Error\n"RESET), 0);
//		if (!check_extension(argv[1]))
//			return (printf(RED"Error\n"RESET), 0);
//		elements = read_elements(argv[1]);
//		map = read_map(argv[1]);
//		if (check_valid_elements(elements, &elements_struct))
//		{
//			if (check_valid_map(map))
//				set_struct_parsing_map(&map_struct, map);
//		}
//		else
//			printf(RED"Error\n"RESET);
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
//		close(fd);
//	}
//	else
//		return (printf(RED"Error\n"RESET), 0);
//	return (0);
//}


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
