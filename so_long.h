/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:01 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/11 00:57:13 by fgarnier         ###   ########.fr       */
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
# define ANIM_DELAY 120

// Vitesse de déplacement
# define SPEED 3

typedef struct s_direction
{
	int			u;
	int			d;
	int			r;
	int			l;

	int			ul;
	int			dl;
	int			ur;
	int			dr;
}				t_direction;

typedef struct s_flood
{
	int			c_found;
	int			e_found;
}				t_flood;

typedef struct s_items
{
	int			c;
	int			e;
	int			p;
}				t_item;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	char		**map;
	int			map_w;
	int			map_h;

	int			player_x;
	int			player_y;

	double		px;
	double		py;
	double		velocity_y;
	int			is_grounded;

	void		*player_idle[5];
	void		*player_idle_flip[5];
	void		*player_run[6];
	void		*player_run_flip[6];
	void		*player_jump[3];
	void		*player_ground[2];

	int			is_running;
	int			facing_left;
	int			is_jumping;
	int			is_landing;

	int			frame;
	long long	last_anim_time;
	void		*bg_player_img;

	int			step;
	int			last_grid_x;
	int			last_grid_y;

	int			remaning_coin;
	void		*coin_img;
	void		*chest_img;
	void		*bg_img;

	t_wall		wall;
	t_floor		floor;
	t_roof		roof;
	t_side		side;
	t_diagonal	diagonal;
	t_corner	corner;

	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	long long	last_move_time;
}				t_game;

int				get_line_nb(char *file_name);
void			get_map(char *file_name, t_game *game);

long long		get_time(void);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				game_loop(t_game *game);

void			move_player(t_game *game, int keycode);
int				close_window(t_game *game);
void			check_interaction(t_game *game);
int				can_move_to(t_game *game, double new_x, double new_y);
int				is_wall_pixel(t_game *game, double x, double y);

void			load_wall(t_game *game, int *w, int *h);
void			load_roof_floor_side(t_game *game, int *w, int *h);
void			load_corner(t_game *game, int *w, int *h);
void			load_diagonal(t_game *game, int *w, int *h);
void			load_diagonal2(t_game *game, int *w, int *h);
void			load_extra(t_game *game, int *w, int *h);
int				load_img(t_game *game);

void			destroy_images(t_game *game);
void			free_all(t_game *game, int specifier);

void			texture_map(t_game *game);

void			*get_wall_texture(t_game *game, int x, int y);
void			*get_corner_1_side(t_game *game, t_direction adj);
void			*get_corner_2_sides(t_game *game, t_direction adj);
void			*get_floor_texture(t_game *game, t_direction adj);
void			*get_roof_texture(t_game *game, t_direction adj);
void			*get_left_wall_texture(t_game *game, t_direction adj);
void			*get_right_wall_texture(t_game *game, t_direction adj);
void			*get_wall_3_sides(t_game *game, t_direction adj);
void			*get_wall_4_sides_2diag(t_game *game, t_direction adj);
void			*get_wall_4_sides(t_game *game, t_direction adj);

void			texture_player(t_game *game, int vertical, int horizontal);
void			free_all(t_game *game, int specifier);
void			free_map(char **map);
int				check_map_walls(char **map);
int				check_elements(char **map, t_item dir, int y);
int				check_map(char **map, t_game *game);
int				check_solvable(char **map, int h, int px, int py);
int				is_rectangular(char **map);
int				is_map_solvable(char **map, int map_h, int player_x,
					int player_y);
int				count_collectibles(char **map);

#endif