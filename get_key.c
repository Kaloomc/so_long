/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:25:26 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 12:53:54 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

double	get_step_y(double velocity_y)
{
	if (velocity_y > 0.0)
		return (1.0);
	return (-1.0);
}

double	get_step_x(double move_x)
{
	if (move_x > 0.0)
		return (1.0);
	return (-1.0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 119)
		game->key_w = 1;
	if (keycode == 97)
	{
		game->key_a = 1;
		game->facing_left = 1;
	}
	if (keycode == 115)
		game->key_s = 1;
	if (keycode == 100)
	{
		game->key_d = 1;
		game->facing_left = 0;
	}
	if (keycode == XK_space && game->is_grounded)
	{
		game->frame = 0;
		game->velocity_y = JUMP_FORCE;
		game->is_grounded = 0;
		game->is_landing = 0;
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key_w = 0;
	if (keycode == 97)
		game->key_a = 0;
	if (keycode == 115)
		game->key_s = 0;
	if (keycode == 100)
		game->key_d = 0;
	return (0);
}
