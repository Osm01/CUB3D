/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_garbage_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:21:35 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/18 13:26:36 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_garbage	*add_new_gar(char *ptr)
{
	t_garbage	*garbage;

	garbage = (t_garbage *) malloc(sizeof (t_garbage));
	if (!garbage)
		return (NULL);
	garbage->ptr = ptr;
	garbage->next = NULL;
	return (garbage);
}

t_garbage	*last_node_gar(t_garbage *garbage)
{
	while (garbage)
	{
		if (garbage->next == NULL)
			return (garbage);
		garbage = garbage->next;
	}
	return (garbage);
}

void	add_back_gar(t_garbage **head, t_garbage *new)
{
	t_garbage	*tmp;

	if (!new)
		return ;
	new->next = NULL;
	if (head && *head)
	{
		tmp = last_node_gar(*head);
		tmp->next = new;
	}
	else
		*head = new;
}
