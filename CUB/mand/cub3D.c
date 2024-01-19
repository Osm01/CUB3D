/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:59:08 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/19 11:46:10 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rendering/cub3D.h"

int	ft_collision(t_game_play *game_play, int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || x >= game_play->map.len_x || y < 0
		|| y >= game_play->map.len_y)
		return (1);
	j = x / TILE_SIZE;
	i = y / TILE_SIZE;
	if (game_play->map.map[i][j] == '1')
		return (1);
	return (0);
}

int	key_pressed(void *param)
{
	t_game_play	*game_play;

	game_play = (t_game_play *)param;
	if (game_play->key_event.esc == 1)
	{
		freeing_parsing_struct(&(game_play->pars));
		exit(0);
	}
	move_player(param);
	rotate_player(param);
	mlx_put_image_to_window(game_play->mlxxx.mlx, game_play->mlxxx.mlx_win,
		game_play->img.img, 0, 0);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_img		img;
	t_game_play	game_play;

	game_play.pars = parsing123(argc, argv);
	initialize_game_play(&game_play, &game_play.pars);
	img.img = mlx_new_image(game_play.mlxxx.mlx, WINDOWS_WIDTH, WINDOWS_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	game_play.img = img;
	ft_draw_loop(&game_play);
	mlx_hook(game_play.mlxxx.mlx_win, 2, 1L << 0, key_pressed1, &game_play);
	mlx_hook(game_play.mlxxx.mlx_win, 3, 1L << 1, key_realsed, &game_play);
	mlx_hook(game_play.mlxxx.mlx_win, 17, 0, close_window, &game_play);
	mlx_loop_hook(game_play.mlxxx.mlx, key_pressed, &game_play);
	mlx_put_image_to_window(game_play.mlxxx.mlx, game_play.mlxxx.mlx_win,
		game_play.img.img, 0, 0);
	mlx_loop(game_play.mlxxx.mlx);
}
