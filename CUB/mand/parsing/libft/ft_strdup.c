/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:49:52 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/05 15:48:42 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	ln;
	char	*str;

	i = 0;
	ln = ft_strlen(s1);
	if (!s1)
		return (0);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		*(str + i) = *(char *)(s1 + i);
		i ++;
	}
	*(str + i) = '\0';
	return (str);
}
