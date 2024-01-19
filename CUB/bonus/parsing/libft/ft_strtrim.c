/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:37:19 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/10 13:02:26 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	find_index_start(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	z;

	z = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		z = 0;
		y = 0;
		while (set[y] != '\0')
		{
			if (s1[i] == set[y])
			{
				z ++;
				break ;
			}
			y ++;
		}
		if (z == 0)
			return (i);
		i ++;
	}
	return (i);
}

static size_t	find_index_end(char const *s1, char const *set, size_t start)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	z;

	i = ft_strlen(s1) - 1;
	while (i > start)
	{
		y = 0;
		z = 0;
		while (set[y] != '\0')
		{
			if (s1[i] == set[y])
			{
				z ++;
				break ;
			}
			y ++;
		}
		if (z == 0)
			return (i);
		i --;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*trim;

	if (!(*s1))
		return (ft_strdup(""));
	if (!set)
		return ((char *)s1);
	start = find_index_start(s1, set);
	end = find_index_end(s1, set, start);
	trim = ft_substr(s1, start, end - start + 1);
	return (trim);
}
