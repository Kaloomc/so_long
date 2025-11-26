/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/26 22:01:14 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_game *game, int *width, int *height)
{
	game->floorImg = mlx_xpm_file_to_image(game->mlx, "textures/Wall/Floor.xpm",
			width, height);
	game->roofImg = mlx_xpm_file_to_image(game->mlx, "textures/Wall/Roof.xpm",
			width, height);
	game->wallLeftImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Wall/Left.xpm", width, height);
	game->wallRightImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Wall/Right.xpm", width, height);
	game->fullImg = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_wall_full.xpm", width, height);
}

void	load_diagonal(t_game *game, int *width, int *height)
{
	game->DiagonalUL = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/UpperLeft.xpm", width, height);
	game->DiagonalUR = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/UpperRight.xpm", width, height);
	game->DiagonalDL = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/DownLeft.xpm", width, height);
	game->DiagonalDR = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/DownRight.xpm", width, height);
	game->DiagonalLeft = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Left.xpm", width, height);
	game->DiagonalRight = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Right.xpm", width, height);
	game->DiagonalDown = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Down.xpm", width, height);
	game->DiagonalUp = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Up.xpm", width, height);
}

void	load_corner(t_game *game, int *width, int *height)
{
	game->corner3SidesRImg = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Right.xpm", width, height);
	game->corner3SidesLImg = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Left.xpm", width, height);
	game->corner3SidesDImg = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Down.xpm", width, height);
	game->corner3SidesUImg = mlx_xpm_file_to_image(game->mlx,
			"textures/3 side/Up.xpm", width, height);
	game->platformV = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/Vertical.xpm", width, height);
	game->platformH = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/Horizontal.xpm", width, height);
	game->SideUL = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/UpperLeft.xpm", width, height);
	game->SideUR = mlx_xpm_file_to_image(game->mlx,
			"textures/2 side/UpperRight.xpm", width, height);
	game->SideDL = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/DownLeft.xpm", width, height);
	game->SideDR = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/DownRight.xpm", width, height);
}

void	load_img(t_game *game)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	load_wall(game, &width, &height);
	load_corner(game, &width, &height);
	load_diagonal(game, &width, &height);
	game->bgImg = mlx_xpm_file_to_image(game->mlx, "textures/Background.xpm",
			&width, &height);
	game->corner4SidesImg = mlx_xpm_file_to_image(game->mlx,
			"textures/4sides.xpm", &width, &height);
}
