/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:02:27 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/16 20:02:59 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_enemy_anim(t_enemy *e)
{
	long long	now;
	int			max;

	now = get_time();
	if (now - e->last_anim_time > 120)
	{
		e->frame++;
		if (e->is_running)
			max = ENEMY_RUN_FRAMES;
		else
			max = ENEMY_IDLE_FRAMES;
		if (e->frame >= max)
			e->frame = 0;
		e->last_anim_time = now;
	}
}

static void	*get_enemy_sprite(t_game *game, t_enemy *e)
{
	if (e->is_running)
	{
		if (!e->facing_left)
			return (game->enemy_run_flip[e->frame % ENEMY_RUN_FRAMES]);
		return (game->enemy_run[e->frame % ENEMY_RUN_FRAMES]);
	}
	else
	{
		if (!e->facing_left)
			return (game->enemy_idle_flip[e->frame % ENEMY_IDLE_FRAMES]);
		return (game->enemy_idle[e->frame % ENEMY_IDLE_FRAMES]);
	}
}

void	render_enemies(t_game *game)
{
	t_enemy	*e;
	void	*img;

	e = game->enemies;
	while (e)
	{
		update_enemy_anim(e);
		update_player_area(game, e->x, e->y);
		img = get_enemy_sprite(game, e);
		if (img)
			mlx_put_image_to_window(game->mlx, game->win, img, (int)e->x,
				(int)e->y);
		e = e->next;
	}
}

void	free_enemies(t_game *game)
{
	t_enemy	*tmp;

	while (game->enemies)
	{
		tmp = game->enemies;
		game->enemies = game->enemies->next;
		free(tmp);
	}
	destroy_enemy_texture(game);
}
