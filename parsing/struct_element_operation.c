/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:27:02 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/07 17:27:02 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_elements	*add_new_element(char *key, char *value)
{
	t_elements	*new_node;

	if (!key || !value)
	{
		if (key)
			free(key);
		else if (value)
			free(value);
		return (NULL);
	}
	new_node = (t_elements *)malloc(sizeof (t_elements));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_elements	*last_element(t_elements *head)
{
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

void	add_back_element(t_elements **head, t_elements *new)
{
	t_elements	*tmp;

	if (!new)
		return ;
	new->next = NULL;
	if (head && *head)
	{
		tmp = last_element(*head);
		tmp->next = new;
	}
	else
		*head = new;
}
