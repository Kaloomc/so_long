/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:25 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 20:14:22 by fgarnier         ###   ########.fr       */
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
	long long now;
	double move_step;
	int i;

	now = get_time();
	if (now - game->last_move_time < 16)
		return (0);

	int has_moved = 0;

	// --- GESTION DE L'AXE Y (Haut/Bas) ---
	if (game->key_w || game->key_s)
	{
		move_step = (game->key_s - game->key_w) * SPEED; // Vaut -3 ou +3

		// On tente de bouger pixel par pixel pour coller au mur
		// On boucle 'SPEED' fois (ex: 3 fois)
		i = 0;
		while (i < SPEED)
		{
			// On essaie d'avancer de 1 pixel dans la direction voulue
			double next_y = game->py + (move_step > 0 ? 1 : -1);

			if (can_move_to(game, game->px, next_y))
			{
				game->py = next_y;
				has_moved = 1;
			}
			else
				break ; // Mur touché ! On arrête d'avancer
			i++;
		}
	}

	// --- GESTION DE L'AXE X (Gauche/Droite) ---
	if (game->key_a || game->key_d)
	{
		move_step = (game->key_d - game->key_a) * SPEED; // Vaut -3 ou +3

		i = 0;
		while (i < SPEED)
		{
			double next_x = game->px + (move_step > 0 ? 1 : -1);

			if (can_move_to(game, next_x, game->py))
			{
				game->px = next_x;
				has_moved = 1;
			}
			else
				break ;
			i++;
		}
	}

	if (has_moved)
	{
		check_interaction(game);
		texture_map(game);

		// Choix du sprite
		void *img = game->player_img;
		if (game->key_a)
			img = game->player_flip_img;
		else if (game->key_d)
			img = game->player_img;
		mlx_put_image_to_window(game->mlx, game->win, img, (int)game->px,
			(int)game->py);
		game->last_move_time = now;
	}
	return (0);
}