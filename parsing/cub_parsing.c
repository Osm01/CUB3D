/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/11 15:21:39 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_elements	*g_elements = NULL;

const char	**read_elements(const char *file_name)
{
	const char	**map_elements;
	char		*read_line;
	int			fd;
	int			i;

	fd = open_file(file_name);
	map_elements = (const char **) malloc(sizeof (char *) * (6 + 1));
	if (!map_elements || fd < 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (i >= 6)
			break ;
		read_line = get_next_line(fd);
		if (!read_line)
			return (NULL);
		if (!ft_strcmp(read_line, "\n"))
			map_elements[i ++] = read_line;
	}
	map_elements[i] = NULL;
	return (close(fd), map_elements);
}

int	valid_two_elements(const char **elem)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	while (elem[i])
	{
		y = 0;
		count = 0;
		while (elem[i][y])
		{
			if (elem[i][y] != ' ' && elem[i][y] != '\t')
			{
				if (!elem[i][y + 1] || elem[i][y + 1] == ' ' \
				|| elem[i][y + 1] == '\t')
					count ++;
			}
			y ++;
		}
		if (count != 2)
			return (0);
		i ++;
	}
	return (1);
}

int	skip_space_and_tabs(const char *elem, int start)
{
	int	i;

	i = start;
	while (elem[i])
	{
		if (elem[i] == ' ' || elem[i] == '\t')
			i ++;
		else
			break ;
	}
	return (i);
}

int	found_space_or_tabs(const char *elem, int start)
{
	int	i;

	i = start;
	while (elem[i])
	{
		if (elem[i] == ' ' || elem[i] == '\t')
			return (i);
		i ++;
	}
	return (i);
}

int	set_struct_elements(const char **elem)
{
	char	*key;
	char	*value;
	int		i;
	int		y;
	int		end;

	if (!valid_two_elements(elem))
		return (0);
	i = 0;
	while (elem[i])
	{
		y = 0;
		while (y < ft_strlen(elem[i]))
		{
			if (y == 0)
			{
				if (elem[i][0] == ' ' || elem[i][y] == '\t')
					y = skip_space_and_tabs(elem[i], 0);
				end = found_space_or_tabs(elem[i], y);
				key = ft_substr(elem[i], y, end - y);
				y = end - 1;
			}
			else
			{
				y = skip_space_and_tabs(elem[i], y);
				end = found_space_or_tabs(elem[i], y);
				value = ft_substr(elem[i], y, (end - y) - 1);
				y = end - 1;
			}
			y ++;
		}
		add_back_element(&g_elements, add_new_element(key, value));
		i ++;
	}
	return (1);
}

int	check_dup_key(struct s_elements *head)
{
	struct s_elements	*tmp;

	tmp = head;
	head = head->next;
	while (head)
	{
		if (ft_strcmp(tmp->key, head->key))
			return (0);
		head = head->next;
	}
	return (1);
}

int	check_valid_elements(const char **elem)
{
	if (!set_struct_elements(elem))
		return (0);
	while (g_elements)
	{
		if (ft_strcmp(g_elements->key, "NO") || ft_strcmp(g_elements->key, "SO") \
		|| ft_strcmp(g_elements->key, "WE") || ft_strcmp(g_elements->key, "EA") \
		|| ft_strcmp(g_elements->key, "F") || ft_strcmp(g_elements->key, "C"))
		{
			if (!check_dup_key(g_elements))
				return (0);
		}
		else
			return (0);
		g_elements = g_elements->next;
	}
	return (1);
}

int	main(int argc, const char *argv[])
{
	const char	**map;

	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			return (0);
		map = read_elements(argv[1]);
		if (check_valid_elements(map))
		{
			printf(GREEN"VALID\n"RESET);
		}
		else
			printf(RED"NOT VALID"RESET);
	}
	else
		printf(RED " NUMBER OF ARG NOT VALID" RESET);
	return (0);
}
