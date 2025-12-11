/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 13:25:05 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_game *game, void **img, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!*img)
	{
		ft_printf("Error\nFailed to load texture: %s\n", path);
		free_all(game, 1);
		exit(1);
	}
}

int	load_img(t_game *game)
{
	load_wall(game);
	load_roof_floor_side(game);
	load_corner(game);
	load_diagonal(game);
	load_extra(game);
	return (1);
}
