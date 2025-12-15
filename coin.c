/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:50:47 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/13 16:00:11 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_coin_animation(t_game *game)
{
	int	y;
	int	x;

	game->coins_frame++;
	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->coin_img[game->coins_frame % 4], x * 32, y * 32);
			x++;
		}
		y++;
	}
}
