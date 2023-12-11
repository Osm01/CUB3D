/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/06 16:44:08 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSING_H
# define CUB_PARSING_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

typedef struct s_elements
{
	char				*key;
	char				*value;
	struct s_elements	*next;
}				t_elements;

extern t_elements	*g_elements;

// ------- CHECK EXTENSION ------- //
int			check_extension(const char *argv);
// ------- MANAGEMENT OF FILE ------- //
int			open_file(const char *file_name);
// ------- MANAGEMENT OF ELEMENTS ------- //
const char	**read_elements(const char *file_name);
int			valid_two_elements(const char **elem);
t_elements	*add_new_element(char *key, char *value);
t_elements	*last_element(t_elements *head);
void		add_back_element(t_elements **head, t_elements *new);

int			ft_strcmp(const char *s1, const char *s2);

#endif //CUB3D_CUB_PARSING_H
