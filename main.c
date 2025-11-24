/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:15:15 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/23 15:18:13 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

int	close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0); // ferme le programme
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	// Initialisation MLX
	mlx = mlx_init();
	if (!mlx)
		return (1);
	// Création de la fenêtre
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");
	if (!win)
		return (1);
	// Hook clavier pour fermer la fenêtre avec ESC
	mlx_hook(win, 2, 1L << 0, close_window, NULL); // KeyPress
	// Boucle principale
	mlx_loop(mlx);
	return (0);
}
