/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:06:06 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/06 18:02:58 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i --;
	}
	return (0);
}
