/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:15:15 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/26 16:45:01 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0); // ferme le programme
	return (0);
}


int	main(void)
{
	t_game	game;

	game.map = get_map("map.ber");
	if (!game.map)
		return (printf("Erreur de map\n"), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	load_img(&game); // ← IMPORTANT : passer l'adresse
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "so_long");
	if (!game.win)
		return (1);
	texture_map(&game);
	mlx_hook(game.win, 2, 1L << 0, close_window, NULL);
	mlx_loop(game.mlx);
	return (0);
}
