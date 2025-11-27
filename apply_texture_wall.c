/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/27 17:25:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wall(t_game *game, int x, int y)
{
	if (y < 0 || !game->map[y])
		return (1);
	if (x < 0 || !game->map[y][x] || game->map[y][x] == '\n')
		return (1);
	return (game->map[y][x] == '1');
}

static void	*get_texture2(t_game *game, int u, int d, int l, int r)
{
	if (!u && !d && l && r)
		return (game->platformH);
	if (u && d && !l && !r)
		return (game->platformV);
	if (u && !d && !l && r)
		return (game->SideDL);
	if (!u && d && !l && r)
		return (game->SideUL);
	if (u && !d && !l && !r)
		return (game->SideDR);
	if (!u && d && l && !r)
		return (game->SideUL);
	return (game->fullImg);
}

static void	*get_texture(t_game *game, int u, int d, int l, int r)
{
	if (!u && d && l && r)
		return (game->floorImg);
	if (u && !d && l && r)
		return (game->roofImg);
	if (u && d && !l && r)
		return (game->wallLeftImg);
	if (u && d && l && !r)
		return (game->wallRightImg);
	if (!u && !d && !l && r)
		return (game->corner3SidesRImg);
	if (!u && !d && l && !r)
		return (game->corner3SidesLImg);
	if (!u && d && !l && !r)
		return (game->corner3SidesUImg);
	if (u && !d && !l && !r)
		return (game->corner3SidesDImg);
	return (game->corner4SidesImg);
}

void	*get_wall_texture(t_game *game, int x, int y)
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	wall_count;

	up = is_wall(game, x, y - 1);
	down = is_wall(game, x, y + 1);
	left = is_wall(game, x - 1, y);
	right = is_wall(game, x + 1, y);
	wall_count = up + down + left + right;
	if (wall_count == 4)
		return (get_diagonal_texture(game, x, y));
	if (wall_count == 2)
		return (get_texture2(game, up, down, left, right));
	return (get_texture(game, up, down, left, right));
}
