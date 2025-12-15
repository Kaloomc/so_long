/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:01 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/15 15:04:43 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "texture.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>

# define TILE_SIZE 32
# define PLAYER_WIDTH 24
# define PLAYER_HEIGHT 28
# define GRAVITY 0.5
# define JUMP_FORCE -9.0
# define ANIM_DELAY 100

# define ENEMY_IDLE_FRAMES 8
# define ENEMY_RUN_FRAMES 6

# define ENEMY_SPEED 1.0
# define SPEED 3

typedef struct s_direction
{
	int				u;
	int				d;
	int				r;
	int				l;

	int				ul;
	int				dl;
	int				ur;
	int				dr;
}					t_direction;

typedef struct s_flood
{
	int				c_found;
	int				e_found;
}					t_flood;

typedef struct s_items
{
	int				c;
	int				e;
	int				p;
}					t_item;

typedef struct s_enemy
{
	double			x;
	double			y;
	double			velocity_y;
	int				is_grounded;
	int				facing_left;
	int				is_running;
	int				frame;
	long long		last_anim_time;
	int				ai_timer;
	int				move_dir;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_game
{
	void			*mlx;
	void			*win;

	char			**map;
	int				map_w;
	int				map_h;

	int				player_x;
	int				player_y;

	double			px;
	double			py;
	double			velocity_y;
	int				is_grounded;

	void			*player_idle[5];
	void			*player_idle_flip[5];
	void			*player_run[6];
	void			*player_run_flip[6];
	void			*player_jump[3];
	void			*player_jump_flip[3];
	void			*player_ground[2];
	void			*player_ground_flip[2];

	void			*coin_img[4];

	void			*enemy_idle[ENEMY_IDLE_FRAMES];
	void			*enemy_idle_flip[ENEMY_IDLE_FRAMES];
	void			*enemy_run[ENEMY_RUN_FRAMES];
	void			*enemy_run_flip[ENEMY_RUN_FRAMES];
	t_enemy			*enemies;

	int				is_running;
	int				facing_left;
	int				is_jumping;
	int				is_landing;

	int				frame;
	int				coins_frame;
	long long		last_anim_time;
	void			*bg_player_img;

	int				step;
	int				last_grid_x;
	int				last_grid_y;

	int				remaning_coin;
	void			*chest_img;
	void			*bg_img;

	t_wall			wall;
	t_floor			floor;
	t_roof			roof;
	t_side			side;
	t_diagonal		diagonal;
	t_corner		corner;

	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	long long		last_move_time;
}					t_game;

void				init_enemies(t_game *game);
void				load_enemy_textures(t_game *game);
void				render_enemies(t_game *game);
void				update_enemies(t_game *game);
void				free_enemies(t_game *game);

void				update_coin_animation(t_game *game);
int					get_line_nb(char *file_name);
void				get_map(char *file_name, t_game *game);

long long			get_time(void);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					game_loop(t_game *game);

void				move_player(t_game *game, int keycode);
int					close_window(t_game *game);
void				check_interaction(t_game *game);
int					can_move_to(t_game *game, double new_x, double new_y);
int					can_enemy_move_to(t_game *game, double new_x, double new_y);
int					is_wall_pixel(t_game *game, double x, double y);

void				load_wall(t_game *game);
void				load_roof_floor_side(t_game *game);
void				load_corner(t_game *game);
void				load_diagonal(t_game *game);
void				load_extra(t_game *game);
int					load_img(t_game *game);
void				load_player_anim(t_game *game);
void				load_coin_anim(t_game *game);
void				load_player_anim_jump_ground(t_game *game);
void				load_player_anim_run(t_game *game);
void				load_texture(t_game *game, void **img, char *path);

void				destroy_images(t_game *game);
void				destroy_image_if(t_game *game, void **img);
void				free_all(t_game *game, int specifier);
void				destroy_player_anim(t_game *game);
void				destroy_player_jump_ground(t_game *game);
void				texture_map(t_game *game);

void				destroy_coin_anim(t_game *game);
void				*get_wall_texture(t_game *game, int x, int y);
void				*get_corner_1_side(t_game *game, t_direction adj);
void				*get_corner_2_sides(t_game *game, t_direction adj);
void				*get_floor_texture(t_game *game, t_direction adj);
void				*get_roof_texture(t_game *game, t_direction adj);
void				*get_left_wall_texture(t_game *game, t_direction adj);
void				*get_right_wall_texture(t_game *game, t_direction adj);
void				*get_wall_3_sides(t_game *game, t_direction adj);
void				*get_wall_4_sides_2diag(t_game *game, t_direction adj);
void				*get_wall_4_sides(t_game *game, t_direction adj);

void				load_texture(t_game *game, void **img, char *path);
int					key_release(int keycode, t_game *game);
int					key_press(int keycode, t_game *game);
double				get_step_x(double move_x);
double				get_step_y(double velocity_y);
void				texture_player(t_game *game, int vertical, int horizontal);
void				free_all(t_game *game, int specifier);
void				free_map(char **map);
int					check_map_walls(char **map);
int					check_elements(char **map, t_item dir, int y);
int					check_map(char **map, t_game *game);
int					check_solvable(char **map, int h, int px, int py);
int					is_rectangular(char **map);
int					is_map_solvable(char **map, int map_h, int player_x,
						int player_y);
int					count_collectibles(char **map);
void				update_player_area(t_game *game, double x, double y);

#endif