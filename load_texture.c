/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 13:24:42 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_game *game)
{
	load_texture(game, &game->wall.alone, "textures/platform.xpm");
	load_texture(game, &game->wall.full, "textures/wall/wall_full.xpm");
	load_texture(game, &game->wall.left, "textures/wall/wall_left.xpm");
	load_texture(game, &game->wall.left_diag_dl,
		"textures/wall/wall_left_diagonal_dl.xpm");
	load_texture(game, &game->wall.left_diag_ul,
		"textures/wall/wall_left_diagonal_ul.xpm");
	load_texture(game, &game->wall.left_diag_r,
		"textures/wall/wall_left_diagonal_right.xpm");
	load_texture(game, &game->wall.right, "textures/wall/wall_right.xpm");
	load_texture(game, &game->wall.right_diag_dr,
		"textures/wall/wall_right_diagonal_dr.xpm");
	load_texture(game, &game->wall.right_diag_l,
		"textures/wall/wall_right_diagonal_left.xpm");
	load_texture(game, &game->wall.right_diag_ur,
		"textures/wall/wall_right_diagonal_ur.xpm");
}

void	load_roof_floor_side(t_game *game)
{
	load_texture(game, &game->floor.floor, "textures/floor/floor.xpm");
	load_texture(game, &game->floor.diag_dl,
		"textures/floor/floor_diagonal_dl.xpm");
	load_texture(game, &game->floor.diag_d,
		"textures/floor/floor_diagonal_down.xpm");
	load_texture(game, &game->floor.diag_dr,
		"textures/floor/floor_diagonal_dr.xpm");
	load_texture(game, &game->roof.roof, "textures/roof/roof.xpm");
	load_texture(game, &game->roof.diag_ul,
		"textures/roof/roof_diagonal_ul.xpm");
	load_texture(game, &game->roof.diag_u,
		"textures/roof/roof_diagonal_up.xpm");
	load_texture(game, &game->roof.diag_ur,
		"textures/roof/roof_diagonal_ur.xpm");
	load_texture(game, &game->side.horizontal, "textures/side/horizontal.xpm");
	load_texture(game, &game->side.vertical, "textures/side/vertical.xpm");
}

void	load_corner(t_game *game)
{
	load_texture(game, &game->corner.dl, "textures/corner/corner_dl.xpm");
	load_texture(game, &game->corner.left, "textures/corner/corner_left.xpm");
	load_texture(game, &game->corner.dl_diag_ur,
		"textures/corner/corner_dl_diagonal_ur.xpm");
	load_texture(game, &game->corner.dr_diag_ul,
		"textures/corner/corner_dr_diagonal_ul.xpm");
	load_texture(game, &game->corner.down, "textures/corner/corner_down.xpm");
	load_texture(game, &game->corner.right, "textures/corner/corner_right.xpm");
	load_texture(game, &game->corner.dr, "textures/corner/corner_dr.xpm");
	load_texture(game, &game->corner.ul, "textures/corner/corner_ul.xpm");
	load_texture(game, &game->corner.up, "textures/corner/corner_up.xpm");
	load_texture(game, &game->corner.up_diag_dr,
		"textures/corner/corner_up_diagonal_dr.xpm");
	load_texture(game, &game->corner.ur, "textures/corner/corner_ur.xpm");
	load_texture(game, &game->corner.ur_diag_dl,
		"textures/corner/corner_ur_diagonal_dl.xpm");
}
