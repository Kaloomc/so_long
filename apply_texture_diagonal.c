/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture_diagonal.c                           :+:      :+:    :+:   */
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

static void	*get_texture(t_game *game, t_direction direction)
{
	if (!direction.l && direction.d && !direction.r && direction.u)
		return (game->diagonalup);
	if (!direction.l && !direction.d && direction.r && direction.u)
		return (game->diagonalleft);
	if (direction.l && direction.d && !direction.r && !direction.u)
		return (game->diagonalright);
	if (direction.l && !direction.d && direction.r && !direction.u)
		return (game->diagonaldown);
	if (!direction.l && direction.d && direction.r && direction.u)
		return (game->diagonal_ul);
	if (direction.l && !direction.d && direction.r && direction.u)
		return (game->diagonal_dl);
	if (direction.l && direction.d && !direction.r && direction.u)
		return (game->diagonal_ur);
	if (direction.l && direction.d && direction.r && !direction.u)
		return (game->diagonal_dr);
	return (game->full_img);
}

void	*get_diagonal_texture(t_game *game, int x, int y)
{
	t_direction	direction;

	direction.l = is_wall(game, x - 1, y - 1);
	direction.d = is_wall(game, x - 1, y + 1);
	direction.r = is_wall(game, x + 1, y - 1);
	direction.u = is_wall(game, x + 1, y + 1);
	return (get_texture(game, direction));
}
