/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 20:59:48 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_exit_and_coin_texture(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		return (game->coin_img);
	if (game->map[y][x] == 'E')
		return (game->chest_img);
	game->player_x = x;
	game->player_y = y;
	game->map[y][x] = '0';
	return (game->bg_img);
}

void	texture_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == '1')
				img = get_wall_texture(game, x, y);
			else if (game->map[y][x] != '0')
				img = get_exit_and_coin_texture(game, x, y);
			else
				img = game->bg_img;
			mlx_put_image_to_window(game->mlx, game->win, img, 32 * x, 32 * y);
			x++;
		}
		y++;
	}
}
