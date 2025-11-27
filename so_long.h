/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:01 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/27 19:45:52 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

// enleve le
# include <stdio.h>
// gros con

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char **map; // tableau 2D contenant la map .ber
	int map_w;  // largeur de la map en cases
	int map_h;  // hauteur de la map en cases

	int win_w; // largeur de la fenêtre en pixels
	int win_h; // hauteur de la fenêtre en pixels

	int player_x; // position du joueur (en cases)
	int		player_y;
	void	*playerIMG;
	int		step;

	int		RemaningCoin;
	void	*coinIMG;

	void	*chestIMG;

	void	*floorImg;
	void	*roofImg;
	void	*wallLeftImg;
	void	*wallRightImg;
	void	*fullImg;
	void	*bgImg;

	void	*corner3SidesRImg;
	void	*corner3SidesLImg;
	void	*corner3SidesUImg;
	void	*corner3SidesDImg;
	void	*corner4SidesImg;
	void	*platformV;
	void	*platformH;

	void	*SideUL;
	void	*SideUR;
	void	*SideDL;
	void	*SideDR;
	void	*DiagonalUL;
	void	*DiagonalUR;
	void	*DiagonalDL;
	void	*DiagonalDR;

	void	*DiagonalLeft;
	void	*DiagonalRight;
	void	*DiagonalDown;
	void	*DiagonalUp;

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

#endif