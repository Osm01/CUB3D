/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:45:15 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/06 11:41:35 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			src_ln;
	unsigned int	offset;

	src_ln = ft_strlen(src);
	offset = 0;
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (src_ln);
	while (*(src + offset) != '\0' && offset < dstsize - 1)
	{
		*(dst + offset) = *(src + offset);
		offset ++;
	}
	*(dst + offset) = '\0';
	return (src_ln);
}
