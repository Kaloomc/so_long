/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/16 20:07:52 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_diagonal(t_game *game)
{
	load_texture(game, &game->diagonal.all,
		"textures/diagonal/diagonal_all.xpm");
	load_texture(game, &game->diagonal.dl, "textures/diagonal/diagonal_dl.xpm");
	load_texture(game, &game->diagonal.d,
		"textures/diagonal/diagonal_down.xpm");
	load_texture(game, &game->diagonal.down_ur,
		"textures/diagonal/diagonal_down_ur.xpm");
	load_texture(game, &game->diagonal.dr, "textures/diagonal/diagonal_dr.xpm");
	load_texture(game, &game->diagonal.left,
		"textures/diagonal/diagonal_left.xpm");
	load_texture(game, &game->diagonal.left_dr,
		"textures/diagonal/diagonal_left_dr.xpm");
	load_texture(game, &game->diagonal.left_ur,
		"textures/diagonal/diagonal_left_ur.xpm");
	load_texture(game, &game->diagonal.right,
		"textures/diagonal/diagonal_right.xpm");
	load_texture(game, &game->diagonal.right_ul,
		"textures/diagonal/diagonal_right_ul.xpm");
	load_texture(game, &game->diagonal.ul, "textures/diagonal/diagonal_ul.xpm");
	load_texture(game, &game->diagonal.ul_dr,
		"textures/diagonal/diagonal_ul_dr.xpm");
	load_texture(game, &game->diagonal.up, "textures/diagonal/diagonal_up.xpm");
	load_texture(game, &game->diagonal.ur, "textures/diagonal/diagonal_ur.xpm");
	load_texture(game, &game->diagonal.ur_dl,
		"textures/diagonal/diagonal_ur_dl.xpm");
}

void	load_extra(t_game *game)
{
	load_texture(game, &game->bg_img, "textures/background.xpm");
	load_texture(game, &game->bg_player_img, "textures/background_player.xpm");
	load_texture(game, &game->chest_img, "textures/chest.xpm");
	load_coin_anim(game);
	load_player_anim(game);
	load_player_anim_run(game);
	load_player_anim_jump_ground(game);
	load_enemy_idle(game);
	load_enemy_run(game);
}
