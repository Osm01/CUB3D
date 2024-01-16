/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:26:00 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/15 18:26:00 by ouidriss         ###   ########.fr       */
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

void	free_elements(t_elements **elements)
{
	t_elements	*tmp;

	if (elements && *elements)
	{
		while (*elements)
		{
			tmp = (*elements);
			*elements = (*elements)->next;
			free(tmp);
		}
	}
}

void	free_floor_ceil(t_floor_ciel **fc)
{
	t_floor_ciel *tmp
	;
	if (fc && *fc)
	{
		while (*fc)
		{
			tmp = *fc;
			*fc = (*fc)->next;
			free(tmp);
		}
	}
}

void	freeing_parsing_struct(t_parsing *parsing)
{
	if (parsing)
	{
		free_elements(&(parsing)->elements);
		freeing_double_pointer((parsing)->map->map);
//		free_floor_ceil(&(parsing)->floor_ciel);
	}
}
