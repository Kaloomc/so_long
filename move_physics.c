/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_physics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:37:27 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/14 11:44:51 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall_pixel(t_game *game, double x, double y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x / 32);
	grid_y = (int)(y / 32);
	if (grid_x < 0 || grid_x >= game->map_w || grid_y < 0
		|| grid_y >= game->map_h)
		return (1);
	return (game->map[grid_y][grid_x] == '1');
}

int	can_move_to(t_game *game, double new_x, double new_y)
{
	double	left;
	double	top;
	double	bottom;
	double	right;

	left = new_x;
	right = new_x + PLAYER_WIDTH - 1;
	top = new_y;
	bottom = new_y + PLAYER_HEIGHT - 1;
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

void	check_interaction(t_game *game)
{
	int		center_x;
	int		center_y;
	char	cell;

	center_x = (int)((game->px + TILE_SIZE / 2) / TILE_SIZE);
	center_y = (int)((game->py + TILE_SIZE / 2) / TILE_SIZE);
	cell = game->map[center_y][center_x];
	if (cell == 'C')
	{
		game->remaning_coin--;
		game->map[center_y][center_x] = '0';
	}
	else if (cell == 'E' && game->remaning_coin == 0)
		close_window(game);
	if (center_x != game->last_grid_x || center_y != game->last_grid_y)
	{
		game->step++;
		ft_printf("Steps: %d\n", game->step);
		game->last_grid_x = center_x;
		game->last_grid_y = center_y;
	}
}
