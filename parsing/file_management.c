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
	char	*find_dot;

	find_dot = ft_strchr(file_name, '.');
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
