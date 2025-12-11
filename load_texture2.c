/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 00:58:09 by fgarnier         ###   ########.fr       */
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

static void	load_player_anim_run(t_game *game, int *w, int *h)
{
	game->player_run[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 01.xpm", w, h);
	game->player_run[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 02.xpm", w, h);
	game->player_run[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 03.xpm", w, h);
	game->player_run[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 04.xpm", w, h);
	game->player_run[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 05.xpm", w, h);
	game->player_run[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 06.xpm", w, h);
	game->player_run_flip[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 01_flip.xpm", w, h);
	game->player_run_flip[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 02_flip.xpm", w, h);
	game->player_run_flip[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 03_flip.xpm", w, h);
	game->player_run_flip[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 04_flip.xpm", w, h);
	game->player_run_flip[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 05_flip.xpm", w, h);
	game->player_run_flip[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/run/Run 06_flip.xpm", w, h);
}

static void	load_player_anim_jump_ground(t_game *game, int *w, int *h)
{
	// JUMP
	game->player_jump[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/jump/Jump 01.xpm", w, h);
	game->player_jump[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/jump/Jump 02.xpm", w, h);
	game->player_jump[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/jump/Jump 03.xpm", w, h);
	// GROUND (Atterrissage)
	game->player_ground[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/ground/Ground 01.xpm", w, h);
	game->player_ground[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/ground/Ground 02.xpm", w, h);
}

static void	load_player_anim_idle_flip(t_game *game, int *w, int *h)
{
	game->player_idle_flip[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_01_flip.xpm", w, h);
	game->player_idle_flip[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_02_flip.xpm", w, h);
	game->player_idle_flip[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_03_flip.xpm", w, h);
	game->player_idle_flip[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_04_flip.xpm", w, h);
	game->player_idle_flip[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_05_flip.xpm", w, h);
}

static void	load_player_anim(t_game *game, int *w, int *h)
{
	game->player_idle[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_01.xpm", w, h);
	game->player_idle[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_02.xpm", w, h);
	game->player_idle[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_03.xpm", w, h);
	game->player_idle[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_04.xpm", w, h);
	game->player_idle[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/idle/Idle_05.xpm", w, h);
	load_player_anim_idle_flip(game, w, h);
}

void	load_extra(t_game *game, int *w, int *h)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "textures/background.xpm",
			w, h);
	game->bg_player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/background_player.xpm", w, h);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", w,
			h);
	game->chest_img = mlx_xpm_file_to_image(game->mlx, "textures/chest.xpm", w,
			h);
	load_player_anim(game, w, h);
	load_player_anim_run(game, w, h);
	load_player_anim_jump_ground(game, w, h);
}
