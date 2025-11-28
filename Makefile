# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 00:46:42 by fgarnier          #+#    #+#              #
#    Updated: 2025/11/28 00:47:22 by fgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRC = so_long.c map_checker.c map_reader.c\
        load_texture.c apply_texture_wall.c \
        apply_texture_diagonal.c apply_texture.c \
        unload_texture.c floodfill.c\
        gnl/get_next_line.c gnl/get_next_line_utils.c

MLX_DIR = mlx
PRINTF_DIR = ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(MLX_DIR) -I$(PRINTF_DIR)

LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(PRINTF_DIR) -lftprintf


OBJ = $(SRC:.c=.o)

all: mlx printf $(NAME)

mlx:
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -C $(MLX_DIR)

printf:
	make -C $(PRINTF_DIR)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re mlx printf