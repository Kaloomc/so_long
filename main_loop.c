/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 23:44:00 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/16 23:48:28 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	long long	now;
	int			was_running;
	void		*img;

	now = get_time();
	if (now - game->last_move_time < 16)
		return (0);
	was_running = game->is_running;
	game->is_running = game->key_a || game->key_d;
	if (was_running != game->is_running)
		game->frame = 0;
	update_anim(game);
	handle_vertical_move(game);
	handle_horizontal_move(game);
	check_interaction(game);
	update_enemies(game);
	img = get_player_sprite(game);
	update_player_area(game, game->px, game->py);
	render_enemies(game);
	mlx_put_image_to_window(game->mlx, game->win, img, (int)game->px,
		(int)game->py);
	display_steps_on_screen(game);
	game->last_move_time = now;
	return (0);
}
