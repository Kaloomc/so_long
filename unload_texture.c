/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:38 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 01:07:21 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	destroy_image_if(t_game *game, void **img)
{
	if (!game || !img || !*img)
		return ;
	if (game->mlx)
		mlx_destroy_image(game->mlx, *img);
	*img = NULL;
}

void	destroy_images(t_game *game)
{
	if (!game)
		return ;
	destroy_image_if(game, &game->floor_img);
	destroy_image_if(game, &game->roof_img);
	destroy_image_if(game, &game->wallleft_img);
	destroy_image_if(game, &game->wallright_img);
	destroy_image_if(game, &game->corner3sidesr_img);
	destroy_image_if(game, &game->corner3sidesl_img);
	destroy_image_if(game, &game->corner3sidesu_img);
	destroy_image_if(game, &game->corner3sidesd_img);
	destroy_image_if(game, &game->corner4sides_img);
	destroy_image_if(game, &game->platform_v);
	destroy_image_if(game, &game->platform_h);
	destroy_image_if(game, &game->side_ul);
	destroy_image_if(game, &game->side_ur);
	destroy_image_if(game, &game->side_dl);
	destroy_image_if(game, &game->side_dr);
	destroy_image_if(game, &game->diagonal_ul);
	destroy_image_if(game, &game->diagonal_ur);
	destroy_image_if(game, &game->diagonal_dl);
	destroy_image_if(game, &game->diagonal_dr);
	destroy_image_if(game, &game->diagonalleft);
	destroy_image_if(game, &game->diagonalright);
	destroy_image_if(game, &game->diagonaldown);
	destroy_image_if(game, &game->diagonalup);
}

static void	destroy_mlx(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

void	free_all(t_game *game, int specifier)
{
	if (!game)
		return ;
	free_map(game->map);
	if (specifier == 1)
	{
		destroy_image_if(game, &game->player_img);
		destroy_image_if(game, &game->coin_img);
		destroy_image_if(game, &game->chest_img);
		destroy_image_if(game, &game->full_img);
		destroy_image_if(game, &game->bg_img);
		destroy_images(game);
	}
	destroy_mlx(game);
}
