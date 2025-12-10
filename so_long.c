/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:15:15 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 21:00:26 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_all(game, 1);
	(void)game;
	exit(0);
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
	game->key_w = 0;
	game->key_a = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->last_move_time = get_time();
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.step = 0;
	if (ac != 2)
		return (0);
	get_map(av[1], &game);
	if (!game.map)
		return (1);
	if (!start(&game))
		return (1);
	if (!load_img(&game))
		return (1);
	game.remaning_coin = count_collectibles(game.map);
	texture_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
