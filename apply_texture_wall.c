/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 01:06:36 by fgarnier         ###   ########.fr       */
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

static void	*get_texture2(t_game *game, t_direction dir)
{
	if (!dir.u && !dir.d && dir.l && dir.r)
		return (game->platform_h);
	if (dir.u && dir.d && !dir.l && !dir.r)
		return (game->platform_v);
	if (dir.u && !dir.d && !dir.l && dir.r)
		return (game->side_dl);
	if (!dir.u && dir.d && !dir.l && dir.r)
		return (game->side_ul);
	if (dir.u && !dir.d && !dir.l && !dir.r)
		return (game->side_dr);
	if (!dir.u && dir.d && dir.l && !dir.r)
		return (game->side_ur);
	return (game->full_img);
}

static void	*get_texture(t_game *game, t_direction dir)
{
	if (!dir.u && dir.d && dir.l && dir.r)
		return (game->floor_img);
	if (dir.u && !dir.d && dir.l && dir.r)
		return (game->roof_img);
	if (dir.u && dir.d && !dir.l && dir.r)
		return (game->wallleft_img);
	if (dir.u && dir.d && dir.l && !dir.r)
		return (game->wallright_img);
	if (!dir.u && !dir.d && !dir.l && dir.r)
		return (game->corner3sidesr_img);
	if (!dir.u && !dir.d && dir.l && !dir.r)
		return (game->corner3sidesl_img);
	if (!dir.u && dir.d && !dir.l && !dir.r)
		return (game->corner3sidesu_img);
	if (dir.u && !dir.d && !dir.l && !dir.r)
		return (game->corner3sidesd_img);
	return (game->corner4sides_img);
}

void	*get_wall_texture(t_game *game, int x, int y)
{
	t_direction	dir;
	int			wall_count;

	dir.u = is_wall(game, x, y - 1);
	dir.d = is_wall(game, x, y + 1);
	dir.l = is_wall(game, x - 1, y);
	dir.r = is_wall(game, x + 1, y);
	wall_count = dir.u + dir.d + dir.l + dir.r;
	if (wall_count == 4)
		return (get_diagonal_texture(game, x, y));
	if (wall_count == 2)
		return (get_texture2(game, dir));
	return (get_texture(game, dir));
}
