/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:15:15 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 01:11:41 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_all(game, 1);
	exit(0);
	return (0);
}

void	move_player(t_game *game, int keycode)
{
	int	directionh;
	int	directionv;

	directionh = 0;
	directionv = 0;
	if (keycode == 100)
		directionh = 1;
	else if (keycode == 97)
		directionh = -1;
	else if (keycode == 119)
		directionv = -1;
	else if (keycode == 115)
		directionv = 1;
	else
		return ;
	if (game->map[game->player_y + directionv][game->player_x
		+ directionh] == '1')
		return ;
	game->step += 1;
	ft_printf("%d\n", game->step);
	texture_player(game, directionv, directionh);
	if (game->remaning_coin == 0
		&& (game->map[game->player_y][game->player_x] == 'E'))
		close_window(game);
}

int	update(int keycode, void *param)
{
	if (keycode == 65307)
		close_window(param);
	move_player(param, keycode);
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_all(game, 0);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->map_w * 32, game->map_h * 32,
			"so_long");
	if (!game->win)
	{
		free_all(game, 0);
		return (0);
	}
	return (1);
}

int	main(void)
{
	t_game	game;

	game.remaning_coin = 0;
	game.step = 0;
	get_map("map/map2.ber", &game);
	if (!game.map)
		return (1);
	if (!start(&game))
		return (1);
	if (!load_img(&game))
		return (1);
	texture_map(&game);
	texture_player(&game, 0, 0);
	mlx_hook(game.win, 2, 1L << 0, update, &game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_loop(game.mlx);
	return (0);
}
