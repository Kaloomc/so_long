/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 20:17:43 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_game *game, int *w, int *h)
{
	game->wall.alone = mlx_xpm_file_to_image(game->mlx, "textures/platform.xpm",
			w, h);
	game->wall.full = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_full.xpm", w, h);
	game->wall.left = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_left.xpm", w, h);
	game->wall.left_diag_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_left_diagonal_dl.xpm", w, h);
	game->wall.left_diag_ul = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_left_diagonal_ul.xpm", w, h);
	game->wall.left_diag_r = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_left_diagonal_right.xpm", w, h);
	game->wall.right = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_right.xpm", w, h);
	game->wall.right_diag_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_right_diagonal_dr.xpm", w, h);
	game->wall.right_diag_l = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_right_diagonal_left.xpm", w, h);
	game->wall.right_diag_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall_right_diagonal_ur.xpm", w, h);
}

void	load_roof_floor_side(t_game *game, int *w, int *h)
{
	game->floor.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor.xpm", w, h);
	game->floor.diag_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_diagonal_dl.xpm", w, h);
	game->floor.diag_d = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_diagonal_down.xpm", w, h);
	game->floor.diag_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor_diagonal_dr.xpm", w, h);
	game->roof.roof = mlx_xpm_file_to_image(game->mlx, "textures/roof/roof.xpm",
			w, h);
	game->roof.diag_ul = mlx_xpm_file_to_image(game->mlx,
			"textures/roof/roof_diagonal_ul.xpm", w, h);
	game->roof.diag_u = mlx_xpm_file_to_image(game->mlx,
			"textures/roof/roof_diagonal_up.xpm", w, h);
	game->roof.diag_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/roof/roof_diagonal_ur.xpm", w, h);
	game->side.horizontal = mlx_xpm_file_to_image(game->mlx,
			"textures/side/horizontal.xpm", w, h);
	game->side.vertical = mlx_xpm_file_to_image(game->mlx,
			"textures/side/vertical.xpm", w, h);
}

void	load_corner(t_game *game, int *w, int *h)
{
	game->corner.dl = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_dl.xpm", w, h);
	game->corner.left = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_left.xpm", w, h);
	game->corner.dl_diag_ur = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_dl_diagonal_ur.xpm", w, h);
	game->corner.dr_diag_ul = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_dr_diagonal_ul.xpm", w, h);
	game->corner.down = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_down.xpm", w, h);
	game->corner.right = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_right.xpm", w, h);
	game->corner.dr = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_dr.xpm", w, h);
	game->corner.ul = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_ul.xpm", w, h);
	game->corner.up = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_up.xpm", w, h);
	game->corner.up_diag_dr = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_up_diagonal_dr.xpm", w, h);
	game->corner.ur = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_ur.xpm", w, h);
	game->corner.ur_diag_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/corner/corner_ur_diagonal_dl.xpm", w, h);
}
