/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 20:03:20 by fgarnier         ###   ########.fr       */
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

void	*get_wall_texture2(t_game *game, t_direction adj)
{
	int	count;

	count = adj.u + adj.d + adj.l + adj.r;
	if (count == 0)
		return (game->wall.full);
	if (count == 1)
		return (get_corner_1_side(game, adj));
	if (count == 2)
		return (get_corner_2_sides(game, adj));
	if (count == 3)
		return (get_wall_3_sides(game, adj));
	if (count == 4)
		return (get_wall_4_sides(game, adj));
	return (game->wall.full);
}

void	*get_wall_texture(t_game *game, int x, int y)
{
	t_direction	dir;
	int			wall_count;
	void		*img;

	dir.u = is_wall(game, x, y - 1);
	dir.d = is_wall(game, x, y + 1);
	dir.l = is_wall(game, x - 1, y);
	dir.r = is_wall(game, x + 1, y);
	dir.ul = is_wall(game, x - 1, y - 1);
	dir.dl = is_wall(game, x - 1, y + 1);
	dir.ur = is_wall(game, x + 1, y - 1);
	dir.dr = is_wall(game, x + 1, y + 1);
	wall_count = dir.d + dir.u + dir.l + dir.r;
	img = get_wall_texture2(game, dir);
	if (wall_count == 0)
		img = game->wall.alone;
	return (img);
}
