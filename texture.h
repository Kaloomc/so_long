/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:03:26 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 19:12:07 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct s_wall
{
	void	*full;
	void	*alone;

	void	*left;
	void	*left_diag_dl;
	void	*left_diag_ul;
	void	*left_diag_r;

	void	*right;
	void	*right_diag_dr;
	void	*right_diag_l;
	void	*right_diag_ur;
}			t_wall;

typedef struct s_floor
{
	void	*floor;
	void	*diag_dl;
	void	*diag_d;
	void	*diag_dr;
}			t_floor;

typedef struct s_roof
{
	void	*roof;
	void	*diag_ul;
	void	*diag_u;
	void	*diag_ur;
}			t_roof;

typedef struct s_side
{
	void	*horizontal;
	void	*vertical;

}			t_side;

typedef struct s_diagonal
{
	void	*all;
	void	*dl;
	void	*d;
	void	*down_ur;
	void	*dr;
	void	*left;
	void	*left_dr;
	void	*left_ur;
	void	*right;
	void	*right_ul;
	void	*ul;
	void	*ul_dr;
	void	*up;
	void	*ur;
	void	*ur_dl;
}			t_diagonal;

typedef struct s_corner
{
	void	*dl;
	void	*dl_diag_ur;
	void	*down;
	void	*dr;
	void	*dr_diag_ul;
	void	*left;
	void	*right;
	void	*ul;
	void	*up;
	void	*ur_diag_dl;
	void	*ur;
	void	*up_diag_dr;
}			t_corner;

#endif