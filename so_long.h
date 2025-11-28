/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:01 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 20:17:20 by fgarnier         ###   ########.fr       */
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

	int			win_w;
	int			win_h;

	int			player_x;
	int			player_y;
	void		*player_img;
	void		*player_flip_img;
	int			step;
	int			total_coin;
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
}				t_game;

int				get_line_nb(char *file_name);
void			get_map(char *file_name, t_game *game);

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

#endif