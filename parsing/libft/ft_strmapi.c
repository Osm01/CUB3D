/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:16:44 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/09 14:03:45 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	size;

	if (!f || !s)
		return (0);
	size = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		*(str + i) = f(i, s[i]);
		i ++;
	}
	*(str + i) = '\0';
	return (str);
}
