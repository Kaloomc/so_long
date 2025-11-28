/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_wall2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 19:46:22 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_corner_1_side(t_game *game, t_direction adj)
{
	if (!adj.u && !adj.d && !adj.l && adj.r)
		return (game->corner.left);
	if (!adj.u && !adj.d && adj.l && !adj.r)
		return (game->corner.right);
	if (!adj.u && adj.d && !adj.l && !adj.r)
		return (game->corner.up);
	if (adj.u && !adj.d && !adj.l && !adj.r)
		return (game->corner.down);
	return (game->wall.full);
}

void	*get_corner_2_sides(t_game *game, t_direction adj)
{
	if (adj.u && adj.d && !adj.l && !adj.r)
		return (game->side.vertical);
	if (!adj.u && !adj.d && adj.l && adj.r)
		return (game->side.horizontal);
	if (!adj.u && adj.d && adj.l && !adj.r && !adj.dl)
		return (game->corner.ur_diag_dl);
	if (!adj.u && adj.d && adj.l && !adj.r)
		return (game->corner.ur);
	if (!adj.u && adj.d && !adj.l && adj.r && !adj.dr)
		return (game->corner.up_diag_dr);
	if (!adj.u && adj.d && !adj.l && adj.r)
		return (game->corner.ul);
	if (adj.u && !adj.d && adj.l && !adj.r && !adj.ul)
		return (game->corner.dr_diag_ul);
	if (adj.u && !adj.d && adj.l && !adj.r)
		return (game->corner.dr);
	if (adj.u && !adj.d && !adj.l && adj.r && !adj.ur)
		return (game->corner.dl_diag_ur);
	if (adj.u && !adj.d && !adj.l && adj.r)
		return (game->corner.dl);
	return (game->wall.full);
}

void	*get_floor_texture(t_game *game, t_direction adj)
{
	if (!adj.dl && !adj.dr)
		return (game->floor.diag_d);
	if (!adj.dl && adj.dr)
		return (game->floor.diag_dr);
	if (adj.dl && !adj.dr)
		return (game->floor.diag_dl);
	return (game->floor.floor);
}

void	*get_roof_texture(t_game *game, t_direction adj)
{
	if (!adj.ul && !adj.ur)
		return (game->roof.diag_u);
	if (!adj.ul && adj.ur)
		return (game->roof.diag_ur);
	if (adj.ul && !adj.ur)
		return (game->roof.diag_ul);
	return (game->roof.roof);
}

void	*get_left_wall_texture(t_game *game, t_direction adj)
{
	if (adj.r && !adj.dl && !adj.ul)
		return (game->wall.left_diag_r);
	if (adj.r && adj.ul)
		return (game->wall.left_diag_ul);
	if (adj.r && !adj.dl)
		return (game->wall.left_diag_dl);
	return (game->wall.left);
}
