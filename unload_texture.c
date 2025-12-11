/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:38 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 01:00:42 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image_if(t_game *game, void **img)
{
	if (!game || !img || !*img)
		return ;
	if (game->mlx)
		mlx_destroy_image(game->mlx, *img);
	*img = NULL;
}

void	destroy_images3(t_game *game)
{
	if (!game)
		return ;
	destroy_image_if(game, &game->corner.dl);
	destroy_image_if(game, &game->corner.dl_diag_ur);
	destroy_image_if(game, &game->corner.down);
	destroy_image_if(game, &game->corner.dr);
	destroy_image_if(game, &game->corner.dr_diag_ul);
	destroy_image_if(game, &game->corner.left);
	destroy_image_if(game, &game->corner.right);
	destroy_image_if(game, &game->corner.ul);
	destroy_image_if(game, &game->corner.up);
	destroy_image_if(game, &game->corner.ur_diag_dl);
	destroy_image_if(game, &game->corner.ur);
	destroy_image_if(game, &game->corner.up_diag_dr);
	// destroy_image_if(game, &game->player_img);
	// destroy_image_if(game, &game->player_flip_img);
	destroy_image_if(game, &game->coin_img);
	destroy_image_if(game, &game->chest_img);
	destroy_image_if(game, &game->bg_img);
	destroy_image_if(game, &game->wall.alone);
}

void	destroy_images2(t_game *game)
{
	if (!game)
		return ;
	destroy_image_if(game, &game->diagonal.all);
	destroy_image_if(game, &game->diagonal.dl);
	destroy_image_if(game, &game->diagonal.d);
	destroy_image_if(game, &game->diagonal.down_ur);
	destroy_image_if(game, &game->diagonal.dr);
	destroy_image_if(game, &game->diagonal.left);
	destroy_image_if(game, &game->diagonal.left_dr);
	destroy_image_if(game, &game->diagonal.left_ur);
	destroy_image_if(game, &game->diagonal.right);
	destroy_image_if(game, &game->diagonal.right_ul);
	destroy_image_if(game, &game->diagonal.ul);
	destroy_image_if(game, &game->diagonal.ul_dr);
	destroy_image_if(game, &game->diagonal.up);
	destroy_image_if(game, &game->diagonal.ur);
	destroy_image_if(game, &game->diagonal.ur_dl);
	destroy_images3(game);
}

void	destroy_images(t_game *game)
{
	if (!game)
		return ;
	destroy_image_if(game, &game->floor.floor);
	destroy_image_if(game, &game->floor.diag_dl);
	destroy_image_if(game, &game->floor.diag_d);
	destroy_image_if(game, &game->floor.diag_dr);
	destroy_image_if(game, &game->roof.roof);
	destroy_image_if(game, &game->roof.diag_ul);
	destroy_image_if(game, &game->roof.diag_u);
	destroy_image_if(game, &game->roof.diag_ur);
	destroy_image_if(game, &game->wall.full);
	destroy_image_if(game, &game->wall.alone);
	destroy_image_if(game, &game->wall.left);
	destroy_image_if(game, &game->wall.left_diag_dl);
	destroy_image_if(game, &game->wall.left_diag_ul);
	destroy_image_if(game, &game->wall.left_diag_r);
	destroy_image_if(game, &game->wall.right);
	destroy_image_if(game, &game->wall.right_diag_dr);
	destroy_image_if(game, &game->wall.right_diag_l);
	destroy_image_if(game, &game->wall.right_diag_ur);
	destroy_image_if(game, &game->side.horizontal);
	destroy_image_if(game, &game->side.vertical);
	destroy_image_if(game, &game->bg_player_img);
	destroy_images2(game);
}
