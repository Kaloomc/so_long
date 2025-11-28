/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 01:07:21 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_diagonal(t_game *game, int *width, int *height)
{
	game->diagonal_ul = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/UpperLeft.xpm", width, height);
	game->diagonal_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/UpperRight.xpm", width, height);
	game->diagonal_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/DownLeft.xpm", width, height);
	game->diagonal_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/DownRight.xpm", width, height);
	game->diagonalleft = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Left.xpm", width, height);
	game->diagonalright = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Right.xpm", width, height);
	game->diagonaldown = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Down.xpm", width, height);
	game->diagonalup = mlx_xpm_file_to_image(game->mlx,
			"textures/Diagonal/Up.xpm", width, height);
}

void	load_corner(t_game *game, int *width, int *height)
{
	game->corner3sidesr_img = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Right.xpm", width, height);
	game->corner3sidesl_img = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Left.xpm", width, height);
	game->corner3sidesd_img = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Down.xpm", width, height);
	game->corner3sidesu_img = mlx_xpm_file_to_image(game->mlx,
			"textures/3 Side/Up.xpm", width, height);
	game->platform_v = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/Vertical.xpm", width, height);
	game->platform_h = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/Horizontal.xpm", width, height);
	game->side_ul = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/UpperLeft.xpm", width, height);
	game->side_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/UpperRight.xpm", width, height);
	game->side_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/DownLeft.xpm", width, height);
	game->side_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/2 Side/DownRight.xpm", width, height);
}

void	load_all(t_game *game, int *width, int *height)
{
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Wall/Floor.xpm", width, height);
	game->roof_img = mlx_xpm_file_to_image(game->mlx, "textures/Wall/Roof.xpm",
			width, height);
	game->wallleft_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Wall/Left.xpm", width, height);
	game->wallright_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Wall/Right.xpm", width, height);
	game->full_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Terrain_wall_full.xpm", width, height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Character/Idle.xpm", width, height);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			width, height);
	game->chest_img = mlx_xpm_file_to_image(game->mlx, "textures/Chest.xpm",
			width, height);
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "textures/Background.xpm",
			width, height);
	game->corner4sides_img = mlx_xpm_file_to_image(game->mlx,
			"textures/4sides.xpm", width, height);
	load_corner(game, width, height);
	load_diagonal(game, width, height);
}

int	load_img(t_game *game)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	load_all(game, &width, &height);
	if (!game->player_img || !game->coin_img || !game->chest_img
		|| !game->floor_img || !game->roof_img || !game->wallleft_img
		|| !game->wallright_img || !game->full_img || !game->bg_img
		|| !game->corner3sidesr_img || !game->corner3sidesl_img
		|| !game->corner3sidesu_img || !game->corner3sidesd_img
		|| !game->corner4sides_img || !game->platform_v || !game->platform_h
		|| !game->side_ul || !game->side_ur || !game->side_dl || !game->side_dr
		|| !game->diagonal_ul || !game->diagonal_ur || !game->diagonal_dl
		|| !game->diagonal_dr || !game->diagonalleft || !game->diagonalright
		|| !game->diagonaldown || !game->diagonalup)
	{
		write(2, "Error\nFailed to load texture\n", 30);
		free_all(game, 1);
		return (0);
	}
	return (1);
}
