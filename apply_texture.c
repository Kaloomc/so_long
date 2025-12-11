/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 10:42:20 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Ajoute ces deux fonctions dans apply_texture.c */

static void	*get_area_texture(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if (c == '1')
		return (get_wall_texture(game, x, y));
	else if (c == 'C')
		return (game->coin_img);
	else if (c == 'E')
		return (game->chest_img);
	return (game->bg_img);
}

void	update_player_area(t_game *game)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	gx = (int)(game->px + 12) / 32;
	gy = (int)(game->py + 14) / 32;
	y = gy - 1;
	while (y <= gy + 1)
	{
		x = gx - 1;
		while (x <= gx + 1)
		{
			if (x >= 0 && x < game->map_w && y >= 0 && y < game->map_h)
				mlx_put_image_to_window(game->mlx, game->win,
					get_area_texture(game, x, y), x * 32, y * 32);
			x++;
		}
		y++;
	}
}

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
