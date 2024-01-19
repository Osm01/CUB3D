/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:16:33 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/09 14:02:27 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !*lst)
		return ;
	tmp = (*lst);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp;
	}
}
