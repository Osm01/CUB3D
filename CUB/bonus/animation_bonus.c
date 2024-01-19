/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:32:01 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/19 11:31:42 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rendering/cub3D.h"

char	**ft_initialize(t_animation *anim)
{
	char	**frames;
	int		i;

	frames = malloc(sizeof (char *) * 7);
	i = -1;
	while (++ i < 6)
		frames[i] = malloc(21);
	ft_strlcpy(frames[0], "TEXTURE/weapon/0.xpm", 21);
	ft_strlcpy(frames[1], "TEXTURE/weapon/1.xpm", 21);
	ft_strlcpy(frames[2], "TEXTURE/weapon/2.xpm", 21);
	ft_strlcpy(frames[3], "TEXTURE/weapon/3.xpm", 21);
	ft_strlcpy(frames[4], "TEXTURE/weapon/4.xpm", 21);
	ft_strlcpy(frames[5], "TEXTURE/weapon/5.xpm", 21);
	frames[6] = NULL;
	anim->index = 0;
	anim->timer = 0;
	anim->start_frames = 0;
	return (frames);
}

void	ft_animation_1(t_game_play *game_play)
{
	int	index;

	index = game_play->animation->index;
	if (game_play->animation->timer % 5 != 0
		&& game_play->animation->start_frames)
	{
		ft_draw_loop(game_play);
		mlx_put_image_to_window(game_play->mlxxx.mlx, game_play->mlxxx.mlx_win,
			game_play->animation->shooting_frames[index],
			(WINDOWS_WIDTH / 2) - (game_play->animation->width[index] / 2),
			WINDOWS_HEIGHT - game_play->animation->height[index]);
	}
	if (game_play->animation->index == 0)
		render_player(game_play);
	else
	{
		if (game_play->animation->timer % 5 == 0)
			game_play->animation->index ++;
	}
	if (game_play->animation->index > 5)
	{
		game_play->animation->index = 0;
		game_play->animation->start_frames = 0;
	}
	game_play->animation->timer ++;
}

void	free_frames(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
}

void	print_and_exit1(char *str)
{
	printf("cannot read image of path : %s\n", str);
	exit(1);
}

void	ft_animation(t_game_play *game_play, t_animation *anim)
{
	void	*img;
	int		width;
	int		height;
	int		i;

	anim->start_frames = 0;
	anim->frames = ft_initialize(anim);
	anim->shooting_frames = (void **) malloc(sizeof (void *) * 7);
	if (!anim->shooting_frames)
		exit (1);
	i = -1;
	while (++i < 6)
	{
		img = mlx_xpm_file_to_image(game_play->mlxxx.mlx, anim->frames[i],
				&width, &height);
		if (!img)
			print_and_exit1(anim->frames[i]);
		anim->shooting_frames[i] = img;
		anim->width[i] = width;
		anim->height[i] = height;
	}
	anim->shooting_frames[i] = NULL;
	game_play->animation = anim;
	free_frames(anim->frames);
}
