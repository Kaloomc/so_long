/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:10:37 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/15 15:06:24 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_enemy_idle(t_game *game)
{
	load_texture(game, &game->enemy_idle[0], "textures/enemy/Idle_01.xpm");
	load_texture(game, &game->enemy_idle[1], "textures/enemy/Idle_02.xpm");
	load_texture(game, &game->enemy_idle[2], "textures/enemy/Idle_03.xpm");
	load_texture(game, &game->enemy_idle[3], "textures/enemy/Idle_04.xpm");
	load_texture(game, &game->enemy_idle[4], "textures/enemy/Idle_05.xpm");
	load_texture(game, &game->enemy_idle[5], "textures/enemy/Idle_06.xpm");
	load_texture(game, &game->enemy_idle[6], "textures/enemy/Idle_07.xpm");
	load_texture(game, &game->enemy_idle[7], "textures/enemy/Idle_08.xpm");
	load_texture(game, &game->enemy_idle_flip[0],
		"textures/enemy/Idle_01_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[1],
		"textures/enemy/Idle_02_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[2],
		"textures/enemy/Idle_03_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[3],
		"textures/enemy/Idle_04_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[4],
		"textures/enemy/Idle_05_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[5],
		"textures/enemy/Idle_06_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[6],
		"textures/enemy/Idle_07_flip.xpm");
	load_texture(game, &game->enemy_idle_flip[7],
		"textures/enemy/Idle_08_flip.xpm");
}

static void	load_enemy_run(t_game *game)
{
	load_texture(game, &game->enemy_run[0], "textures/enemy/Run_01.xpm");
	load_texture(game, &game->enemy_run[1], "textures/enemy/Run_02.xpm");
	load_texture(game, &game->enemy_run[2], "textures/enemy/Run_03.xpm");
	load_texture(game, &game->enemy_run[3], "textures/enemy/Run_04.xpm");
	load_texture(game, &game->enemy_run[4], "textures/enemy/Run_05.xpm");
	load_texture(game, &game->enemy_run[5], "textures/enemy/Run_06.xpm");
	load_texture(game, &game->enemy_run_flip[0],
		"textures/enemy/Run_01_flip.xpm");
	load_texture(game, &game->enemy_run_flip[1],
		"textures/enemy/Run_02_flip.xpm");
	load_texture(game, &game->enemy_run_flip[2],
		"textures/enemy/Run_03_flip.xpm");
	load_texture(game, &game->enemy_run_flip[3],
		"textures/enemy/Run_04_flip.xpm");
	load_texture(game, &game->enemy_run_flip[4],
		"textures/enemy/Run_05_flip.xpm");
	load_texture(game, &game->enemy_run_flip[5],
		"textures/enemy/Run_06_flip.xpm");
}

void	load_enemy_textures(t_game *game)
{
	load_enemy_idle(game);
	load_enemy_run(game);
}

static void	add_enemy(t_game *game, int x, int y)
{
	t_enemy	*new;
	t_enemy	*tmp;

	new = malloc(sizeof(t_enemy));
	if (!new)
		return ;
	new->x = (x * 32);
	new->y = (y * 32);
	new->velocity_y = 0;
	new->is_grounded = 0;
	new->facing_left = 0;
	new->is_running = 0;
	new->frame = 0;
	new->last_anim_time = 0;
	new->ai_timer = 0;
	new->move_dir = 0;
	new->next = NULL;
	if (!game->enemies)
		game->enemies = new;
	else
	{
		tmp = game->enemies;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	init_enemies(t_game *game)
{
	int x;
	int y;

	game->enemies = NULL;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X')
			{
				add_enemy(game, x, y);
				game->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}