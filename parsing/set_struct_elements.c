/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_element_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:16 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/12 11:02:29 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	skip_space_and_tabs(char *elem, int start)
{
	int	i;

	i = start;
	while (elem[i])
	{
		if (elem[i] == ' ' || elem[i] == '\t')
			i ++;
		else
			break ;
	}
	return (i);
}

int	found_space_or_tabs(char *elem, int start)
{
	int	i;

	i = start;
	while (elem[i])
	{
		if (elem[i] == ' ' || elem[i] == '\t')
			return (i);
		i ++;
	}
	return (i);
}

int	set_key_and_value(char *elem, int y, char **key, char **value)
{
	int	end;

	if (y == 0)
	{
		if (elem[0] == ' ' || elem[y] == '\t')
			y = skip_space_and_tabs(elem, 0);
		end = found_space_or_tabs(elem, y);
		*key = ft_substr(elem, y, end - y);
		y = end - 1;
	}
	else
	{
		y = skip_space_and_tabs(elem, y);
//		end = found_space_or_tabs(elem, y);
//		*value = ft_substr(elem, y, (end - y) - 1);
		*value = ft_substr(elem, y, ft_strlen(elem) - 1);
		y = ft_strlen(elem) - 1;
	}
	return (y);
}

int	set_struct_elements(char **elem, t_elements **t_elem)
{
	char	*key;
	char	*value;
	int		i;
	size_t	y;

	if (!valid_two_elements(elem))
		return (0);
	i = 0;
	while (elem[i])
	{
		key = NULL;
		value = NULL;
		y = 0;
		while (y < ft_strlen(elem[i]))
		{
			y = set_key_and_value(elem[i], y, &key, &value);
			y ++;
		}
		add_back_element(t_elem, add_new_element(key, value));
		i ++;
	}
	return (1);
}
