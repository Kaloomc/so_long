/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:35:07 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 20:01:00 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	player_position(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->px = (game->player_x * 32) + 5;
				game->py = (game->player_y * 32) + 12;
				game->last_grid_x = game->player_x;
				game->last_grid_y = game->player_y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_elements(char **map, t_item obj, int y)
{
	int	x;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				obj.p++;
			else if (map[y][x] == 'E')
				obj.e++;
			else if (map[y][x] == 'C')
				obj.c++;
			x++;
		}
		y++;
	}
	if (obj.p != 1 || obj.e != 1 || obj.c < 1)
		ft_printf("Error\nThere is too few/not enough elements\n");
	return (obj.p == 1 && obj.e == 1 && obj.c >= 1);
}

int	check_map_walls(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (((y == 0 || !map[y + 1]) && map[y][x] != '1') || ((x == 0
						|| !map[y][x + 1] || map[y][x + 1] == '\n')
					&& map[y][x] != '1'))
			{
				ft_printf("Error\nMap not surrounded by walls\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	invalid_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'E'
				&& map[y][x] != 'C' && map[y][x] != 'P')
			{
				ft_printf("Error\nInvalid Character\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(char **map, t_game *game)
{
	t_item	items;

	items.p = 0;
	items.e = 0;
	items.c = 0;
	if (!is_rectangular(map) || !check_map_walls(map) || !invalid_char(map)
		|| !check_elements(map, items, 0))
		return (0);
	player_position(game, map);
	if ((!is_map_solvable(map, game->map_h, game->player_x, game->player_y)))
	{
		ft_printf("Error\nMap unsolvable\n");
		return (0);
	}
	if (game->map_w > 60 || game->map_h > 30)
	{
		ft_printf("Error\nMap too big\n");
		return (0);
	}
	return (1);
}
