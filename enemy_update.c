/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:41:09 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/16 20:05:20 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_ai_move(t_game *game, t_enemy *e)
{
	int		i;
	double	next_x;

	if (e->move_dir == 0)
		return ;
	i = 0;
	while (i < (int)ENEMY_SPEED)
	{
		if (e->move_dir > 0)
			next_x = e->x + 1;
		else
			next_x = e->x + -1;
		if (can_enemy_move_to(game, next_x, e->y) && check_ground_ahead(game, e,
				next_x))
			e->x = next_x;
		else
		{
			e->move_dir = 0;
			e->is_running = 0;
			break ;
		}
		i++;
	}
}

static void	enemy_ai_think(t_enemy *e)
{
	int	rand_choice;

	e->ai_timer--;
	if (e->ai_timer <= 0)
	{
		rand_choice = rand() % 3;
		if (rand_choice == 0)
		{
			e->move_dir = 0;
			e->is_running = 0;
		}
		else
		{
			e->move_dir = 1;
			if (rand_choice != 1)
				e->move_dir = -1;
			e->facing_left = (e->move_dir == -1);
			e->is_running = 1;
		}
		e->ai_timer = 60 + (rand() % 120);
	}
}

void	update_enemies(t_game *game)
{
	t_enemy	*e;

	e = game->enemies;
	while (e)
	{
		enemy_physics_y(game, e);
		if (e->is_grounded)
		{
			enemy_ai_think(e);
			enemy_ai_move(game, e);
		}
		if (check_player_collision(game, e))
		{
			ft_printf("Game Over: Touched by enemy!\n");
			close_window(game);
		}
		e = e->next;
	}
}
