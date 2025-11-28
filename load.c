/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 20:13:18 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correctly_loaded(t_game *game)
{
	return (!game->player_img || !game->coin_img || !game->chest_img
		|| !game->floor.floor || !game->floor.diag_dl || !game->floor.diag_d
		|| !game->floor.diag_dr || !game->roof.roof || !game->roof.diag_ul
		|| !game->roof.diag_u || !game->roof.diag_ur || !game->wall.full
		|| !game->wall.alone || !game->wall.left || !game->wall.left_diag_dl
		|| !game->wall.left_diag_ul || !game->wall.left_diag_r
		|| !game->wall.right || !game->wall.right_diag_dr
		|| !game->wall.right_diag_l || !game->wall.right_diag_ur
		|| !game->side.horizontal || !game->side.vertical || !game->corner.dl
		|| !game->corner.dl_diag_ur || !game->corner.down || !game->corner.dr
		|| !game->corner.dr_diag_ul || !game->corner.left || !game->corner.right
		|| !game->corner.ul || !game->corner.up || !game->corner.ur_diag_dl
		|| !game->corner.ur || !game->corner.up_diag_dr || !game->diagonal.all
		|| !game->diagonal.dl || !game->diagonal.d || !game->diagonal.down_ur
		|| !game->diagonal.dr || !game->diagonal.left || !game->diagonal.left_dr
		|| !game->diagonal.left_ur || !game->diagonal.right
		|| !game->diagonal.right_ul || !game->diagonal.ul
		|| !game->diagonal.ul_dr || !game->diagonal.up
		|| !game->diagonal.ur || !game->diagonal.ur_dl);
}

int	load_img(t_game *game)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	load_wall(game, &width, &height);
	load_roof_floor_side(game, &width, &height);
	load_corner(game, &width, &height);
	load_diagonal(game, &width, &height);
	load_extra(game, &width, &height);
	if (correctly_loaded(game))
	{
		write(2, "Error\nFailed to load texture\n", 30);
		free_all(game, 1);
		return (0);
	}
	return (1);
}
