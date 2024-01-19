/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_element_addic.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:50:58 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/15 16:51:00 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	count_semicolone(char *value)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (value[++i])
	{
		if (value[i] == ',')
			count ++;
	}
	return (count);
}

int	check_number_value(char **rgb)
{
	int	i;
	int	y;
	int	count;
	int	nb;

	i = -1;
	while (rgb[++i])
	{
		y = -1;
		count = 0;
		nb = 0;
		while (rgb[i][++y])
		{
			if (rgb[i][y] >= '0' && rgb[i][y] <= '9')
			{
				nb ++;
				if (rgb[i][y + 1] < '0' || rgb[i][y + 1] > '9')
					if (rgb[i][y + 1] != '\n' && rgb[i][y + 1] != 0)
						count ++;
			}
		}
		if (count || nb == 0)
			return (0);
	}
	return (1);
}

int	check_valid_value_of_walls(t_elements *elem)
{
	int		i;
	int		count;

	while (elem)
	{
		if (ft_strlen(elem->key) > 1)
		{
			i = 0;
			count = 0;
			while (elem->value[i])
			{
				if (elem->value[i] != ' ' && elem->value[i] != '\t')
				{
					if (!elem->value[i + 1] || elem->value[i + 1] == '\t' || \
					elem->value[i + 1] == ' ')
						count ++;
				}
				i ++;
			}
			if (count != 1)
				return (0);
		}
		elem = elem->next;
	}
	return (1);
}
