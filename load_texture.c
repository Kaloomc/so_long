/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/26 17:53:03 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_game *game, int *width, int *height)
{
	game->floorImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_floor.xpm", width, height);
	game->roofImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_roof.xpm", width, height);
	game->wallLeftImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_wall_left.xpm", width, height);
	game->wallRightImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_wall_right.xpm", width, height);
	game->fullImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_wall_full.xpm", width, height);
}

void	load_3sides(t_game *game, int *width, int *height)
{
	game->corner3SidesRImg = mlx_xpm_file_to_image(game->mlx,
			"textures/corner3sidesR.xpm", width, height);
	game->corner3SidesLImg = mlx_xpm_file_to_image(game->mlx,
			"textures/corner3sidesL.xpm", width, height);
	game->corner3SidesDImg = mlx_xpm_file_to_image(game->mlx,
			"textures/corner3sidesD.xpm", width, height);
	game->corner3SidesUImg = mlx_xpm_file_to_image(game->mlx,
			"textures/corner3sidesU.xpm", width, height);
}

void	load_img(t_game *game)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	load_wall(game, &width, &height);
	load_3sides(game, &width, &height);
	game->bgImg = mlx_xpm_file_to_image(game->mlx, "textures/Background.xpm",
			&width, &height);
	game->corner4SidesImg = mlx_xpm_file_to_image(game->mlx,
			"textures/4sides.xpm", &width, &height);
	if (!game->floorImg || !game->roofImg || !game->wallRightImg
		|| !game->wallLeftImg || !game->fullImg || !game->bgImg)
		printf("Erreur chargement texture\n");
}
