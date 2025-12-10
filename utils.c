/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:25 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 19:56:40 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		close_window(game);
	if (keycode == 119) // W
		game->key_w = 1;
	if (keycode == 97) // A
		game->key_a = 1;
	if (keycode == 115) // S
		game->key_s = 1;
	if (keycode == 100) // D
		game->key_d = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119) // W
		game->key_w = 0;
	if (keycode == 97) // A
		game->key_a = 0;
	if (keycode == 115) // S
		game->key_s = 0;
	if (keycode == 100) // D
		game->key_d = 0;
	return (0);
}

int	game_loop(t_game *game)
{
	long long now = get_time();
	// On update plus souvent (ex: toutes les 16ms = ~60fps) pour que ce soit fluide
	if (now - game->last_move_time < 16)
		return (0);

	double new_px = game->px;
	double new_py = game->py;
	int has_moved = 0;

	// Calcul de la future position
	if (game->key_w)
	{
		new_py -= SPEED;
		has_moved = 1;
	}
	if (game->key_s)
	{
		new_py += SPEED;
		has_moved = 1;
	}
	if (game->key_a)
	{
		new_px -= SPEED;
		has_moved = 1;
	}
	if (game->key_d)
	{
		new_px += SPEED;
		has_moved = 1;
	}

	if (has_moved)
	{
		// On teste X et Y séparément pour permettre de "glisser" contre les murs
		if (can_move_to(game, new_px, game->py))
			game->px = new_px;
		if (can_move_to(game, game->px, new_py))
			game->py = new_py;

		check_interaction(game);

		// RENDER
		// 1. Redessiner toute la map (pour effacer la trace du joueur)
		texture_map(game);

		// 2. Dessiner le joueur à sa position précise (cast en int pour mlx)
		void *img = game->player_img;
		// Sens du regard
		mlx_put_image_to_window(game->mlx, game->win, img, (int)game->px,
			(int)game->py);

		game->last_move_time = now;
	}
	return (0);
}