/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:26:00 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/16 16:05:20 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

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

void	free_elements(t_parsing *parsing)
{
	t_elements	*tmp;

	if (parsing->elements)
	{
		while (parsing->elements)
		{
			tmp = parsing->elements->next;
			free(parsing->elements->value);
			free(parsing->elements->key);
			free(parsing->elements);
			parsing->elements = tmp;
		}
	}
}

void	free_floor_ceil(t_parsing *parsing)
{
	t_floor_ciel	*tmp;

	if (parsing->floor_ciel)
	{
		while (parsing->floor_ciel)
		{
			tmp = parsing->floor_ciel->next;
			free(parsing->floor_ciel);
			parsing->floor_ciel = tmp;
		}
	}
}

void	free_map(t_parsing *parsing)
{
	int	i;

	if (parsing->map)
	{
		i = 0;
		while (parsing->map->map[i])
			free(parsing->map->map[i ++]);
		free(parsing->map->map);
		free(parsing->map);
	}
}

void	freeing_parsing_struct(t_parsing *parsing)
{
	if (parsing)
	{
		free_elements(parsing);
		free_floor_ceil(parsing);
		free_map(parsing);
	}
}
