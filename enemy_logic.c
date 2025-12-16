/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:02:57 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/16 20:02:02 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player_collision(t_game *game, t_enemy *e)
{
	t_hitbox	player;
	t_hitbox	enemy;

	player.left = game->px;
	player.right = game->px + PLAYER_WIDTH;
	player.top = game->py;
	player.bottom = game->py + PLAYER_HEIGHT;
	enemy.left = e->x + 4;
	enemy.right = e->x + 28;
	enemy.top = e->y + 4;
	enemy.bottom = e->y + 28;
	if (player.left < enemy.right && player.right > enemy.left
		&& player.top < enemy.bottom && player.bottom > enemy.top)
		return (1);
	return (0);
}

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

int	check_ground_ahead(t_game *game, t_enemy *e, double next_x)
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

static void	enemy_velocity_y(t_game *game, t_enemy *e, double step)
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
		return ;
	}
}

void	enemy_physics_y(t_game *game, t_enemy *e)
{
	double	step;
	int		pixels;
	int		i;

	e->velocity_y += 0.5;
	if (e->velocity_y > 10.0)
		e->velocity_y = 10.0;
	step = 1.0;
	if (e->velocity_y <= 0)
		step = -1.0;
	pixels = (int)abs((int)e->velocity_y);
	i = 0;
	while (i < pixels)
	{
		enemy_velocity_y(game, e, step);
		i++;
	}
}
