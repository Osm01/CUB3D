/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ciel_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:29:19 by ouidriss          #+#    #+#             */
/*   Updated: 2024/01/13 15:29:19 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_floor_ciel	*add_new_floor_ceil(char *key, char *value)
{
	t_floor_ciel	*floor_ciel;
	char			**split_value;
	int				i;
	int				v;
	unsigned int	shifting;

	floor_ciel = (t_floor_ciel *)malloc(sizeof (t_floor_ciel));
	if (!floor_ciel)
		return (NULL);
	if (ft_strcmp(key, "F"))
		floor_ciel->key = 'F';
	else if (ft_strcmp(key, "C"))
		floor_ciel->key = 'C';
	split_value = ft_split(value, ',');
	i = 0;
	v = 0;
	shifting = 16;
	while (split_value[i])
	{
		v |= ft_atoi(split_value[i ++]) << shifting;
		shifting -= 8;
	}
	floor_ciel->value = v;
	floor_ciel->next = NULL;
	return (freeing_double_pointer(split_value), floor_ciel);
}

t_floor_ciel	*last_element_floor_ciel(t_floor_ciel *head)
{
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

void	add_back_floor_ceil(t_floor_ciel **head, t_floor_ciel *new)
{
	t_floor_ciel	*tmp;

	if (!new)
		return ;
	if (head && *head)
	{
		tmp = last_element_floor_ciel(*head);
		tmp->next = new;
	}
	else
		*head = new;
}
