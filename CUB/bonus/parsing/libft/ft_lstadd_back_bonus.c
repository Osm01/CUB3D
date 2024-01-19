/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:06:39 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/08 18:27:48 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_add;

	if (!new)
		return ;
	if (lst && *lst)
	{
		last_add = ft_lstlast(*lst);
		last_add->next = new;
	}
	else
		(*lst) = new;
}
