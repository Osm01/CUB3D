/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:57:56 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/06 17:55:35 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i ++;
	}
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
