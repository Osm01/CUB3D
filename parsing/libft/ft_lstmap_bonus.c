/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:17:10 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/09 14:32:08 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*test;
	t_list	*re;

	if (!lst || !f || !del)
		return (NULL);
	test = lst;
	re = 0;
	while (lst != NULL)
	{
		test = ft_lstnew(f(test->content));
		if (!test)
		{
			ft_lstclear(&re, del);
			break ;
		}
		ft_lstadd_back(&re, test);
		lst = lst->next;
		test = lst;
	}
	return (re);
}
