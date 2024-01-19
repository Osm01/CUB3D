/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:31:02 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/18 18:35:52 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*return_path(t_parsing *parsing1, char *direction)
{
	int					i;
	struct s_elements	*elem;

	i = 0;
	elem = parsing1->elements;
	while (elem)
	{
		if (ft_strcmp(elem->key, direction) == 1)
			return (elem->value);
		i++;
		elem = elem->next;
	}
	return (NULL);
}

void	initialize_text_north(t_game_play *game_play, t_parsing *parsing1)
{
	char	*addr;
	void	*texture;
	char	*path;

	path = return_path(parsing1, "NO");
	path[ft_strlen(path) - 1] = 0;
	texture = mlx_xpm_file_to_image(game_play->mlxxx.mlx,
			path,
			&game_play->texture.tex_north_width,
			&game_play->texture.tex_north_height);
	if (!texture)
	{
		printf("unable to load texture no\n");
		exit(1);
	}
	game_play->texture.north_texture.img = texture;
	addr = mlx_get_data_addr(game_play->texture.north_texture.img,
			&game_play->texture.north_texture.bits_per_pixel,
			&game_play->texture.north_texture.line_length,
			&game_play->texture.north_texture.endian);
	game_play->texture.north_texture.addr = addr;
}

void	initialize_text_south(t_game_play *game_play, t_parsing *parsing1)
{
	char	*addr;
	void	*texture;
	char	*path;

	path = return_path(parsing1, "SO");
	path[ft_strlen(path) - 1] = 0;
	texture = mlx_xpm_file_to_image(game_play->mlxxx.mlx,
			path,
			&game_play->texture.tex_south_width,
			&game_play->texture.tex_south_height);
	if (!texture)
	{
		printf("unable to load texture so\n");
		exit(1);
	}
	game_play->texture.south_texture.img = texture;
	addr = mlx_get_data_addr(game_play->texture.south_texture.img,
			&game_play->texture.south_texture.bits_per_pixel,
			&game_play->texture.south_texture.line_length,
			&game_play->texture.south_texture.endian);
	game_play->texture.south_texture.addr = addr;
}

void	initialize_text_west(t_game_play *game_play, t_parsing *parsing1)
{
	char	*addr;
	void	*texture;
	char	*path;

	path = return_path(parsing1, "WE");
	path[ft_strlen(path) - 1] = 0;
	texture = mlx_xpm_file_to_image(game_play->mlxxx.mlx,
			path,
			&game_play->texture.tex_west_width,
			&game_play->texture.tex_west_height);
	if (!texture)
	{
		printf("unable to load texture we\n");
		exit(1);
	}
	game_play->texture.west_texture.img = texture;
	addr = mlx_get_data_addr(game_play->texture.west_texture.img,
			&game_play->texture.west_texture.bits_per_pixel,
			&game_play->texture.west_texture.line_length,
			&game_play->texture.west_texture.endian);
	game_play->texture.west_texture.addr = addr;
}

void	initialize_text_east(t_game_play *game_play, t_parsing *parsing1)
{
	char	*addr;
	void	*texture;
	char	*path;

	path = return_path(parsing1, "EA");
	path[ft_strlen(path) - 1] = 0;
	texture = mlx_xpm_file_to_image(game_play->mlxxx.mlx,
			path,
			&game_play->texture.tex_est_width,
			&game_play->texture.tex_est_height);
	if (!texture)
	{
		printf("unable to load texture ea\n");
		exit(1);
	}
	game_play->texture.est_texture.img = texture;
	addr = mlx_get_data_addr(game_play->texture.est_texture.img,
			&game_play->texture.est_texture.bits_per_pixel,
			&game_play->texture.est_texture.line_length,
			&game_play->texture.est_texture.endian);
	game_play->texture.est_texture.addr = addr;
}
