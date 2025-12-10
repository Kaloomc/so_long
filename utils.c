/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:25 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 20:57:44 by fgarnier         ###   ########.fr       */
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
	if (keycode == XK_space && game->is_grounded)
	{
		game->velocity_y = JUMP_FORCE;
		game->is_grounded = 0;
	}
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
	int has_moved;

	now = get_time();
	if (now - game->last_move_time < 16) // ~60 FPS
		return (0);
	mlx_put_image_to_window(game->mlx, game->win, game->bg_player_img,
		(int)game->px, (int)game->py);

	has_moved = 0;
	game->velocity_y += 0.5;

	if (game->velocity_y > 10.0)
		game->velocity_y = 10.0;
	double step_y = (game->velocity_y > 0) ? 1.0 : -1.0;
	int pixels_to_move = (int)abs((int)game->velocity_y);

	int i = 0;
	while (i < pixels_to_move)
	{
		if (can_move_to(game, game->px, game->py + step_y))
		{
			game->py += step_y;
			game->is_grounded = 0;
			has_moved = 1;
		}
		else
		{
			if (game->velocity_y > 0)
				game->is_grounded = 1;
			else
				game->velocity_y = 0;

			game->velocity_y = 0;
			break ;
		}
		i++;
	}

	if (game->key_a || game->key_d)
	{
		double move_x = (game->key_d - game->key_a) * SPEED;
		double step_x = (move_x > 0) ? 1.0 : -1.0;

		i = 0;
		while (i < SPEED)
		{
			if (can_move_to(game, game->px + step_x, game->py))
			{
				game->px += step_x;
				has_moved = 1;
			}
			else
				break ;
			i++;
		}
	}
	if (has_moved || game->velocity_y != 0)
	{
		check_interaction(game);
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
