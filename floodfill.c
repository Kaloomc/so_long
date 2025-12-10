/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:00:56 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/10 20:39:09 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Fonction 1 : Copier la map
char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	if (!map || height <= 0)
		return (NULL);
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height && map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// Fonction 2 : Libérer la copie de la map
void	free_map_copy(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// Fonction 3 : Flood fill récursif
void	flood_fill(char **map, int x, int y, t_flood *flood)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		flood->c_found++;
	if (map[y][x] == 'E')
		flood->e_found = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, flood);
	flood_fill(map, x - 1, y, flood);
	flood_fill(map, x, y + 1, flood);
	flood_fill(map, x, y - 1, flood);
}

// Fonction 4 : Compter le nombre total de collectibles
int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

// Fonction 5 : Vérifier si la map est solvable
int	is_map_solvable(char **map, int map_h, int player_x, int player_y)
{
	char	**map_copy;
	t_flood	flood;
	int		total_c;
	int		result;

	if (!map || map_h <= 0)
		return (0);
	map_copy = copy_map(map, map_h);
	if (!map_copy)
	{
		free_map_copy(map_copy);
		return (0);
	}
	flood.c_found = 0;
	flood.e_found = 0;
	total_c = count_collectibles(map);
	flood_fill(map_copy, player_x, player_y, &flood);
	result = (flood.c_found == total_c && flood.e_found == 1);
	free_map_copy(map_copy);
	return (result);
}
