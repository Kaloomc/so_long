/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 13:20:46 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_anim_run(t_game *game)
{
	load_texture(game, &game->player_run[0], "textures/run/Run 01.xpm");
	load_texture(game, &game->player_run[1], "textures/run/Run 02.xpm");
	load_texture(game, &game->player_run[2], "textures/run/Run 03.xpm");
	load_texture(game, &game->player_run[3], "textures/run/Run 04.xpm");
	load_texture(game, &game->player_run[4], "textures/run/Run 05.xpm");
	load_texture(game, &game->player_run[5], "textures/run/Run 06.xpm");
	load_texture(game, &game->player_run_flip[0],
		"textures/run/Run 01_flip.xpm");
	load_texture(game, &game->player_run_flip[1],
		"textures/run/Run 02_flip.xpm");
	load_texture(game, &game->player_run_flip[2],
		"textures/run/Run 03_flip.xpm");
	load_texture(game, &game->player_run_flip[3],
		"textures/run/Run 04_flip.xpm");
	load_texture(game, &game->player_run_flip[4],
		"textures/run/Run 05_flip.xpm");
	load_texture(game, &game->player_run_flip[5],
		"textures/run/Run 06_flip.xpm");
}

void	load_player_anim_jump_ground(t_game *game)
{
	load_texture(game, &game->player_jump[0], "textures/jump/Jump 01.xpm");
	load_texture(game, &game->player_jump[1], "textures/jump/Jump 02.xpm");
	load_texture(game, &game->player_jump[2], "textures/jump/Jump 03.xpm");
	load_texture(game, &game->player_jump_flip[0],
		"textures/jump/Jump 01_flip.xpm");
	load_texture(game, &game->player_jump_flip[1],
		"textures/jump/Jump 02_flip.xpm");
	load_texture(game, &game->player_jump_flip[2],
		"textures/jump/Jump 03_flip.xpm");
	load_texture(game, &game->player_ground[0],
		"textures/ground/Ground 01.xpm");
	load_texture(game, &game->player_ground[1],
		"textures/ground/Ground 02.xpm");
	load_texture(game, &game->player_ground_flip[0],
		"textures/ground/Ground 01_flip.xpm");
	load_texture(game, &game->player_ground_flip[1],
		"textures/ground/Ground 02_flip.xpm");
}

void	load_player_anim(t_game *game)
{
	load_texture(game, &game->player_idle[0], "textures/idle/Idle_01.xpm");
	load_texture(game, &game->player_idle[1], "textures/idle/Idle_02.xpm");
	load_texture(game, &game->player_idle[2], "textures/idle/Idle_03.xpm");
	load_texture(game, &game->player_idle[3], "textures/idle/Idle_04.xpm");
	load_texture(game, &game->player_idle[4], "textures/idle/Idle_05.xpm");
	load_texture(game, &game->player_idle_flip[0],
		"textures/idle/Idle_01_flip.xpm");
	load_texture(game, &game->player_idle_flip[1],
		"textures/idle/Idle_02_flip.xpm");
	load_texture(game, &game->player_idle_flip[2],
		"textures/idle/Idle_03_flip.xpm");
	load_texture(game, &game->player_idle_flip[3],
		"textures/idle/Idle_04_flip.xpm");
	load_texture(game, &game->player_idle_flip[4],
		"textures/idle/Idle_05_flip.xpm");
}
