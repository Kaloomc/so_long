/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 20:05:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_diagonal(t_game *game, int *w, int *h)
{
	game->diagonal.all = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_all.xpm", w, h);
	game->diagonal.dl = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_dl.xpm", w, h);
	game->diagonal.d = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_down.xpm", w, h);
	game->diagonal.down_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_down_ur.xpm", w, h);
	game->diagonal.dr = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_dr.xpm", w, h);
	game->diagonal.left = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_left.xpm", w, h);
	game->diagonal.left_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_left_dr.xpm", w, h);
	game->diagonal.left_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_left_ur.xpm", w, h);
	game->diagonal.right = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_right.xpm", w, h);
	game->diagonal.right_ul = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_right_ul.xpm", w, h);
	load_diagonal2(game, w, h);
}

void	load_diagonal2(t_game *game, int *w, int *h)
{
	game->diagonal.ul = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_ul.xpm", w, h);
	game->diagonal.ul_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_ul_dr.xpm", w, h);
	game->diagonal.up = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_up.xpm", w, h);
	game->diagonal.ur = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_ur.xpm", w, h);
	game->diagonal.ur_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/diagonal/diagonal_ur_dl.xpm", w, h);
}

void	load_extra(t_game *game, int *w, int *h)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "textures/background.xpm",
			w, h);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/Idle.xpm", w,
			h);
	game->player_flip_img = mlx_xpm_file_to_image(game->mlx,
			"textures/Idle_flip.xpm", w, h);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", w,
			h);
	game->chest_img = mlx_xpm_file_to_image(game->mlx, "textures/chest.xpm", w,
			h);
}
