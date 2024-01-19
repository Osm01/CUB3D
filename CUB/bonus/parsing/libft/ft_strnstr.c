/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:19:30 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/09 18:36:48 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, unsigned long n)
{
	size_t			i;
	size_t			y;
	unsigned long	z;

	i = 0;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		y = 0;
		if (s1[i] == s2[y])
		{
			z = i;
			while (s2[y] != '\0' && s2[y] == s1[z] && z < n)
			{
				y ++;
				z ++;
			}
			if (y == ft_strlen(s2))
				return ((char *)(s1 + i));
		}
		i ++;
	}
	return (0);
}
