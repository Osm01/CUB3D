/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:51:37 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/11 17:26:05 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSING_H
# define CUB_PARSING_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

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

typedef struct s_map
{
	char	**map;
	char	player;
}				t_map;

typedef struct s_floor_ciel
{
	char				key;
	unsigned int		value;
	struct s_floor_ciel	*next;
}				t_floor_ciel;

typedef struct s_parsing
{
	t_elements		*elements;
	t_map			*map;
	t_floor_ciel	*floor_ciel;
}				t_parsing;

typedef struct s_garbage
{
	char				*ptr;
	struct s_garbage	*next;
}								t_garbage;

// ------- CHECK EXTENSION ------- //
int				check_extension(const char *argv);
// ------- MANAGEMENT OF FILE ------- //
int				open_file(const char *file_name);
// ------- STRUCT OF ELEMENTS OPERATION ------- //
t_elements		*add_new_element(char *key, char *value);
t_elements		*last_element(t_elements *head);
void			add_back_element(t_elements **head, t_elements *new);
// ------- MANAGEMENT OF ELEMENTS ------- //
char			**read_elements(const char *file_name);
int				valid_two_elements(char **elem);
int				set_struct_elements(char **elem, t_elements **t_elem);
int				check_valid_elements(char **elem, t_elements **t_elem);
// ------- STRUCT OF ELEMENTS OPERATION ------- //
t_floor_ciel	*add_new_floor_ceil(char *key, char *value);
t_floor_ciel	*last_element_floor_ciel(t_floor_ciel *head);
void			add_back_floor_ceil(t_floor_ciel **head, t_floor_ciel *new);
// ------- MANAGEMENT OF MAP ------- //
char			**read_map(const char *file_name);
int				check_valid_map(char **map);
int				check_element_of_map(char **map);
char			player_dir(char **map);
int				index_first_element_of_map(char *line);
int				count_map(char **map);
void			removing_new_lines_end(char **map);
// ------- MANAGEMENT OF LEAKS ------- //
t_garbage		*add_new_gar(char *ptr);
t_garbage		*last_node_gar(t_garbage *garbage);
void			add_back_gar(t_garbage **head, t_garbage *new);
void			freeing_double_pointer(char **ptr);
void			set_struct_parsing_map(t_map **map_struct, char **map);

int				ft_strcmp(const char *s1, const char *s2);

#endif //CUB3D_CUB_PARSING_H
