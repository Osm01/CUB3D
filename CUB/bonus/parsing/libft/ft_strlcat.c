/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:55:33 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/09 13:50:03 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			src_ln;
	size_t			dst_ln;
	unsigned int	offset;

	dst_ln = ft_strlen(dst);
	src_ln = ft_strlen(src);
	offset = 0;
	if (!dst && !dstsize)
		return (src_ln);
	if (dstsize <= dst_ln)
		return (src_ln + dstsize);
	while (*(src + offset) != '\0' && offset < dstsize - dst_ln - 1)
	{
		*(dst + (dst_ln + offset)) = *(src + offset);
		offset ++;
	}
	*(dst + (dst_ln + offset)) = '\0';
	return (dst_ln + src_ln);
}
