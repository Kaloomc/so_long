/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_wall3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:44:18 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 19:40:37 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_right_wall_texture(t_game *game, t_direction adj)
{
	if (!adj.dr && !adj.ur)
		return (game->wall.right_diag_l);
	if (adj.l && !adj.dl)
		return (game->wall.right_diag_ur);
	if (adj.l && !adj.dr)
		return (game->wall.right_diag_dr);
	return (game->wall.right);
}

void	*get_wall_3_sides(t_game *game, t_direction adj)
{
	if (!adj.u && adj.d && adj.l && adj.r)
		return (get_floor_texture(game, adj));
	if (adj.u && !adj.d && adj.l && adj.r)
		return (get_roof_texture(game, adj));
	if (adj.u && adj.d && !adj.l && adj.r)
		return (get_right_wall_texture(game, adj));
	if (adj.u && adj.d && adj.l && !adj.r)
		return (get_left_wall_texture(game, adj));
	return (game->wall.full);
}

void	*get_wall_4_sides_2diag(t_game *game, t_direction adj)
{
	if (!adj.ul && !adj.dr)
		return (game->diagonal.ul_dr);
	if (!adj.ur && !adj.dl)
		return (game->diagonal.ur_dl);
	if (!adj.ul && !adj.ur)
		return (game->diagonal.up);
	if (!adj.dl && !adj.dr)
		return (game->diagonal.d);
	if (!adj.ul && !adj.dl)
		return (game->diagonal.left);
	if (!adj.ur && !adj.dr)
		return (game->diagonal.right);
	return (game->wall.full);
}

void	*get_wall_4_sides(t_game *game, t_direction adj)
{
	int	diag_count;

	diag_count = adj.ul + adj.ur + adj.dl + adj.dr;
	if (diag_count == 4)
		return (game->wall.full);
	if (diag_count == 0)
		return (game->diagonal.all);
	if (diag_count == 3)
	{
		if (!adj.ul)
			return (game->diagonal.ul);
		if (!adj.ur)
			return (game->diagonal.ur);
		if (!adj.dl)
			return (game->diagonal.dr);
		return (game->diagonal.dl);
	}
	return (get_wall_4_sides_2diag(game, adj));
}
