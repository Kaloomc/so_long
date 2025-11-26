/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/26 17:53:55 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkside(t_game *game, int x, int y)
{
	int	emptyside;

	emptyside = 0;
	if ((*game).map[x + 1] && (*game).map[y][x + 1] != '1')
		emptyside++;
	if (x != 0 && (*game).map[y][x - 1] != '1')
		emptyside++;
	if ((*game).map[y + 1] && (*game).map[y + 1][x] != '1')
		emptyside++;
	if (y != 0 && (*game).map[y - 1][x] != '1')
		emptyside++;
	return (4 - emptyside);
}

void	*corner(t_game *game, int x, int y)
{
		if ((*game).map[x + 1] && (*game).map[y][x + 1] == '1')
			return ((*game).corner3SidesRImg);
		if ((*game).map[x - 1] && (*game).map[y][x - 1] == '1')
			return ((*game).corner3SidesLImg);
		if ((*game).map[y - 1] && (*game).map[y - 1][x] == '1')
			return ((*game).corner3SidesDImg);
		return ((*game).corner3SidesUImg);
}

void	*wall(t_game *game, int x, int y)
{
	if (checkside(game, x, y) != 4 && checkside(game, x, y) != 3
		&& checkside(game, x, y) != 0)
		return (corner(game, x, y));
	if (checkside(game, x, y) == 0)
		return ((*game).corner4SidesImg);
	else if ((*game).map[x + 1] && (*game).map[y][x + 1] != '1')
		return ((*game).wallRightImg);
	else if ((*game).map[x + 1] && (*game).map[y][x + 1] != '1')
		return ((*game).wallRightImg);
	else if (x != 0 && (*game).map[y][x - 1] != '1')
		return ((*game).wallLeftImg);
	else if ((*game).map[y + 1] && (*game).map[y + 1][x] != '1')
		return ((*game).roofImg);
	else if (y != 0 && (*game).map[y - 1][x] != '1')
		return ((*game).floorImg);
	return ((*game).fullImg);
}

void	texture_map(t_game *game)
{
	int		x;
	int		y;
	void	*img_to_print;

	x = 0;
	y = 0;
	while ((*game).map[y])
	{
		while ((*game).map[y][x] && (*game).map[y][x] != '\n')
		{
			if ((*game).map[y][x] == '1')
				img_to_print = wall(game, x, y);
			else
				img_to_print = (*game).bgImg;
			mlx_put_image_to_window((*game).mlx, (*game).win, img_to_print, 32
				* x, 32 * y);
			x++;
		}
		y++;
		x = 0;
	}
}
