/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture_diagonal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/27 16:35:42 by fgarnier         ###   ########.fr       */
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

static void	*get_texture(t_game *game, int ul, int dl, int ur, int dr)
{
	if (!ul && dl && !ur && dr)
		return (game->DiagonalUp);
	if (!ul && !dl && ur && dr)
		return (game->DiagonalLeft);
	if (ul && dl && !ur && !dr)
		return (game->DiagonalRight);
	if (ul && !dl && ur && !dr)
		return (game->DiagonalDown);
	if (!ul && dl && ur && dr)
		return (game->DiagonalUL);
	if (ul && !dl && ur && dr)
		return (game->DiagonalDL);
	if (ul && dl && !ur && dr)
		return (game->DiagonalUR);
	if (ul && dl && ur && !dr)
		return (game->DiagonalDR);
	return (game->fullImg);
}

void	*get_diagonal_texture(t_game *game, int x, int y)
{
	int	upLeft;
	int	downLeft;
	int	upRight;
	int	downRight;

	upLeft = is_wall(game, x - 1, y - 1);
	downLeft = is_wall(game, x - 1, y + 1);
	upRight = is_wall(game, x + 1, y - 1);
	downRight = is_wall(game, x + 1, y + 1);
	return (get_texture(game, upLeft, downLeft, upRight, downRight));
}
