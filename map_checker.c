/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:35:07 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/25 19:35:24 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	is_rectangular(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_linelen(map[i]) != ft_linelen(map[i - 1]))
			return (0);
		i++;
	}
	return (1);
}
int	get_line_nb(char *file_name)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_map(char *file_name)
{
	int		fd;
	int		nb_line;
	char	**map;
	int		i;

	i = 0;
	nb_line = get_line_nb(file_name);
	if (nb_line <= 2)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	while (i <= nb_line)
		map[i++] = get_next_line(fd);
	close(fd);
	return (map);
}

char	**get_map(char *file_name)
{
	char **map;

	map = read_map(file_name);
	if (!map || !is_rectangular(map))
		return (NULL);
	return (map);
}