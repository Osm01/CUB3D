/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:29:03 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/07 17:29:03 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	check_extension(const char *file_name)
{
	const char	*find_dot;
	int			i;

	if (!file_name)
		return (0);
	find_dot = NULL;
	i = ft_strlen(file_name) - 1;
	while (i >= 0)
	{
		if (file_name[i] == '.')
		{
			find_dot = file_name + i;
			break ;
		}
		i --;
	}
	if (!find_dot)
		return (0);
	return (ft_strcmp(find_dot, ".cub"));
}

int	open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error open file"), -1);
	return (fd);
}
