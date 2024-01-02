/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:27:16 by ouidriss          #+#    #+#             */
/*   Updated: 2023/12/19 12:27:16 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"
# define WIDTH 600
# define HEIGHT 600

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "../parsing/cub_parsing.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define A_KEY 97
# define D_KEY 100
# define W_KEY 119
# define S_KEY 115
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define ESC_KEY 65307

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_player
{
	double 		x_player;
	double 		y_player;
	int 		speed;
	double		current_angle;
	t_vars		*vars;
	t_map		*map;
}				t_player;

typedef struct s_vector
{
	int x_position;
	int y_position;
}				t_vector;

#endif
