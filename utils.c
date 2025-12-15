/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:10:25 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/13 18:28:30 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_anim(t_game *game)
{
	long long	now;
	int			max_frames;

	max_frames = 6;
	now = get_time();
	if (now - game->last_anim_time > ANIM_DELAY)
	{
		game->frame++;
		if (!game->is_grounded && game->frame >= 2)
			game->frame = max_frames - 1;
		else if (game->is_landing && game->frame >= 2)
		{
			game->is_landing = 0;
			game->frame = 0;
		}
		else if (game->frame >= max_frames)
			game->frame = 0;
		update_coin_animation(game);
		game->last_anim_time = now;
	}
}

static int	handle_vertical_move(t_game *game)
{
	double	step_y;
	int		pixels_to_move;
	int		i;
	int		has_moved;

	has_moved = 0;
	game->velocity_y += 0.5;
	if (game->velocity_y > 10.0)
		game->velocity_y = 10.0;
	step_y = get_step_y(game->velocity_y);
	pixels_to_move = (int)abs((int)game->velocity_y);
	i = 0;
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
			if (game->velocity_y > 0.0 && game->is_grounded == 0)
			{
				game->is_grounded = 1;
				game->is_landing = 1;
				game->frame = 0;
			}
			game->velocity_y = 0.0;
			break ;
		}
		i++;
	}
	return (has_moved);
}

static int	handle_horizontal_move(t_game *game)
{
	double	move_x;
	double	step_x;
	int		i;
	int		has_moved;

	has_moved = 0;
	if (game->key_a || game->key_d)
	{
		move_x = (game->key_d - game->key_a) * SPEED;
		step_x = get_step_x(move_x);
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
	return (has_moved);
}

void	*get_player_sprite(t_game *game)
{
	void	*img;

	if (game->is_landing && game->facing_left)
		img = game->player_ground_flip[game->frame % 2];
	else if (game->is_landing)
		img = game->player_ground[game->frame % 2];
	else if (!game->is_grounded && game->facing_left)
		img = game->player_jump_flip[game->frame % 3];
	else if (!game->is_grounded)
		img = game->player_jump[game->frame % 3];
	else if (game->is_running && game->facing_left)
		img = game->player_run_flip[game->frame % 6];
	else if (game->is_running)
		img = game->player_run[game->frame % 6];
	else if (game->facing_left)
		img = game->player_idle_flip[game->frame % 5];
	else
		img = game->player_idle[game->frame % 5];
	return (img);
}

int	game_loop(t_game *game)
{
	long long	now;
	int			moved;
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
	moved = handle_vertical_move(game);
	moved += handle_horizontal_move(game);
	check_interaction(game);
	update_enemies(game);
	img = get_player_sprite(game);
	update_player_area(game,game->px, game->py);
	render_enemies(game);
	mlx_put_image_to_window(game->mlx, game->win, img, (int)game->px,
		(int)game->py);
	game->last_move_time = now;
	return (0);
}
