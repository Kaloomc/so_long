/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:02:57 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/15 16:03:19 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_enemy_move_to(t_game *game, double new_x, double new_y)
{
	double	left;
	double	right;
	double	top;
	double	bottom;

	left = new_x + 1;
	right = new_x + 31;
	top = new_y;
	bottom = new_y + 27;
	if (is_wall_pixel(game, left, top))
		return (0);
	if (is_wall_pixel(game, right, top))
		return (0);
	if (is_wall_pixel(game, left, bottom))
		return (0);
	if (is_wall_pixel(game, right, bottom))
		return (0);
	return (1);
}

static int	check_ground_ahead(t_game *game, t_enemy *e, double next_x)
{
	int	grid_x;
	int	grid_y;

	if (e->facing_left)
		grid_x = (int)((next_x + 1) / 32);
	else
		grid_x = (int)((next_x + 30) / 32);
	grid_y = (int)((e->y + 30) / 32);
	if (grid_y >= game->map_h || grid_x < 0 || grid_x >= game->map_w)
		return (0);
	return (game->map[grid_y][grid_x] == '1');
}

static void	enemy_physics_y(t_game *game, t_enemy *e)
{
	double	step;
	int		pixels;
	int		i;

	e->velocity_y += 0.5;
	if (e->velocity_y > 10.0)
		e->velocity_y = 10.0;
	step = (e->velocity_y > 0) ? 1.0 : -1.0;
	pixels = (int)abs((int)e->velocity_y);
	i = 0;
	while (i < pixels)
	{
		if (can_enemy_move_to(game, e->x, e->y + step + 1))
		{
			e->y += step;
			e->is_grounded = 0;
		}
		else
		{
			if (e->velocity_y > 0)
				e->is_grounded = 1;
			e->velocity_y = 0;
			break ;
		}
		i++;
	}
}

static void	enemy_ai_move(t_game *game, t_enemy *e)
{
	int		i;
	double	next_x;

	if (e->move_dir == 0)
		return ;
	i = 0;
	while (i < (int)ENEMY_SPEED)
	{
		next_x = e->x + (e->move_dir > 0 ? 1 : -1);
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
			e->facing_left = (e->move_dir == -1);
			e->move_dir = (rand_choice == 1) ? -1 : 1;
			e->is_running = 1;
		}
		e->ai_timer = 60 + (rand() % 120);
	}
}

void	update_enemies(t_game *game)
{
	t_enemy *e;

	e = game->enemies;
	while (e)
	{
		enemy_physics_y(game, e);
		if (e->is_grounded)
		{
			enemy_ai_think(e);
			enemy_ai_move(game, e);
		}
		e = e->next;
	}
}