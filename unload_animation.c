/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:38 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/13 16:04:51 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_player_anim(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		destroy_image_if(game, &game->player_idle[i]);
		destroy_image_if(game, &game->player_idle_flip[i]);
	}
	i = -1;
	while (++i < 6)
	{
		destroy_image_if(game, &game->player_run[i]);
		destroy_image_if(game, &game->player_run_flip[i]);
	}
}

void	destroy_player_jump_ground(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		destroy_image_if(game, &game->player_jump[i]);
		destroy_image_if(game, &game->player_jump_flip[i]);
	}
	i = -1;
	while (++i < 2)
	{
		destroy_image_if(game, &game->player_ground[i]);
		destroy_image_if(game, &game->player_ground_flip[i]);
	}
}

void	destroy_enemy_texture(t_game *game)
{
	int	i;

	i = -1;
	while (++i < ENEMY_IDLE_FRAMES)
	{
		destroy_image_if(game, &game->enemy_idle[i]);
		destroy_image_if(game, &game->enemy_idle_flip[i]);
	}
	i = -1;
	while (++i < ENEMY_RUN_FRAMES)
	{
		destroy_image_if(game, &game->enemy_run[i]);
		destroy_image_if(game, &game->enemy_run_flip[i]);
	}
}

void	destroy_coin_anim(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		destroy_image_if(game, &game->coin_img[i]);
}
