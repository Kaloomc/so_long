/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:38 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/27 19:47:49 by fgarnier         ###   ########.fr       */
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
	destroy_image_if(game, &game->floorImg);
	destroy_image_if(game, &game->roofImg);
	destroy_image_if(game, &game->wallLeftImg);
	destroy_image_if(game, &game->wallRightImg);
	destroy_image_if(game, &game->corner3SidesRImg);
	destroy_image_if(game, &game->corner3SidesLImg);
	destroy_image_if(game, &game->corner3SidesUImg);
	destroy_image_if(game, &game->corner3SidesDImg);
	destroy_image_if(game, &game->corner4SidesImg);
	destroy_image_if(game, &game->platformV);
	destroy_image_if(game, &game->platformH);
	destroy_image_if(game, &game->SideUL);
	destroy_image_if(game, &game->SideUR);
	destroy_image_if(game, &game->SideDL);
	destroy_image_if(game, &game->SideDR);
	destroy_image_if(game, &game->DiagonalUL);
	destroy_image_if(game, &game->DiagonalUR);
	destroy_image_if(game, &game->DiagonalDL);
	destroy_image_if(game, &game->DiagonalDR);
	destroy_image_if(game, &game->DiagonalLeft);
	destroy_image_if(game, &game->DiagonalRight);
	destroy_image_if(game, &game->DiagonalDown);
	destroy_image_if(game, &game->DiagonalUp);
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
		destroy_image_if(game, &game->playerIMG);
		destroy_image_if(game, &game->coinIMG);
		destroy_image_if(game, &game->chestIMG);
		destroy_image_if(game, &game->fullImg);
		destroy_image_if(game, &game->bgImg);
		destroy_images(game);
	}
	destroy_mlx(game);
}
