/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:01 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 00:57:06 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_direction
{
	int		u;
	int		d;
	int		r;
	int		l;
	int		p;
	int		e;
	int		c;
}			t_direction;

typedef struct s_flood
{
	int		c_found;
	int		e_found;
}			t_flood;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_w;
	int		map_h;

	int		win_w;
	int		win_h;

	int		player_x;
	int		player_y;
	void	*player_img;
	int		step;
	int		total_coin;
	int		remaning_coin;
	void	*coin_img;

	void	*chest_img;

	void	*floor_img;
	void	*roof_img;
	void	*wallleft_img;
	void	*wallright_img;
	void	*full_img;
	void	*bg_img;

	void	*corner3sidesr_img;
	void	*corner3sidesl_img;
	void	*corner3sidesu_img;
	void	*corner3sidesd_img;
	void	*corner4sides_img;
	void	*platform_v;
	void	*platform_h;

	void	*side_ul;
	void	*side_ur;
	void	*side_dl;
	void	*side_dr;
	void	*diagonal_ul;
	void	*diagonal_ur;
	void	*diagonal_dl;
	void	*diagonal_dr;

	void	*diagonalleft;
	void	*diagonalright;
	void	*diagonaldown;
	void	*diagonalup;

}			t_game;

int			get_line_nb(char *file_name);
void		get_map(char *file_name, t_game *game);
int			load_img(t_game *game);
void		texture_map(t_game *game);
void		*get_wall_texture(t_game *game, int x, int y);
void		*get_diagonal_texture(t_game *game, int x, int y);
void		texture_player(t_game *game, int vertical, int horizontal);
void		free_all(t_game *game, int specifier);
void		free_map(char **map);
int			check_map_walls(char **map);
int			check_elements(char **map, t_direction dir, int y);
int			check_map(char **map, t_game *game);
int			check_solvable(char **map, int h, int px, int py);
int			is_rectangular(char **map);
int			is_map_solvable(char **map, int map_h, int player_x, int player_y);

#endif