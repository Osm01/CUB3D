/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:48:52 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/16 17:51:29 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	valid_two_elements(char **elem)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	while (elem[i])
	{
		y = 0;
		count = 0;
		while (elem[i][y])
		{
			if (elem[i][y] != ' ' && elem[i][y] != '\t')
			{
				if (!elem[i][y + 1] || elem[i][y + 1] == ' ' \
				|| elem[i][y + 1] == '\t')
					count ++;
			}
			y ++;
		}
		if (count != 2)
			return (0);
		i ++;
	}
	return (1);
}

int	check_dup_key(t_elements *head)
{
	t_elements	*tmp;

	tmp = head;
	head = head->next;
	while (head)
	{
		if (ft_strcmp(tmp->key, head->key))
			return (0);
		head = head->next;
	}
	return (1);
}

int	check_valid_value_addictional(char **rgb, int i)
{
	int	y;

	i = 0;
	while (rgb[i])
	{
		y = 0;
		while (rgb[i][y])
		{
			if (rgb[i][y] < '0' || rgb[i][y] > '9')
				return (0);
			y ++;
		}
		i ++;
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (0);
		i ++;
	}
	return (1);
}

int	check_valid_value(t_elements *elem)
{
	int		i;
	char	**rgb;

	while (elem)
	{
		if (ft_strlen(elem->key) == 1)
		{
			i = 0;
			rgb = ft_split(elem->value, ',');
			while (rgb[i])
				i ++;
			if (i == 3)
			{
				if (!check_valid_value_addictional(rgb, i))
					return (freeing_double_pointer(rgb), 0);
				freeing_double_pointer(rgb);
			}
			else
				return (0);
		}
		elem = elem->next;
	}
	return (1);
}

int	check_valid_elements(char **elem, t_elements **t_elem)
{
	t_elements	*tmp;

	if (!set_struct_elements(elem, t_elem))
		return (0);
	tmp = *t_elem;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "NO") || ft_strcmp(tmp->key, "SO") \
		|| ft_strcmp(tmp->key, "WE") || ft_strcmp(tmp->key, "EA") \
		|| ft_strcmp(tmp->key, "F") || ft_strcmp(tmp->key, "C"))
		{
			if (!check_dup_key(tmp))
				return (0);
		}
		else
			return (0);
		tmp = tmp->next;
	}
	if (!check_valid_value(*t_elem))
		return (0);
	return (1);
}
