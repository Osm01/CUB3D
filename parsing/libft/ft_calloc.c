/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:45:46 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/05 17:49:12 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(unsigned long count, unsigned long size)
{
	unsigned long	i;
	unsigned char	*alloc;

	i = 0;
	alloc = (unsigned char *)malloc(size * count);
	if (!alloc)
		return (0);
	ft_bzero(alloc, count * size);
	return (alloc);
}
