# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 09:54:52 by fgarnier          #+#    #+#              #
#    Updated: 2025/12/10 19:38:56 by fgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Imlx -I. -Ignl -Ift_printf

MLX_DIR     = mlx
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

PRINTF_DIR  = ft_printf
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

SRCS        = so_long.c \
              utils.c \
              load_texture.c  \
			  load_texture2.c  \
			  load.c  \
			  unload_texture.c \
			  unload.c \
              apply_texture.c \
              get_texture_wall.c \
			  get_texture_wall2.c \
			  get_texture_wall3.c \
              map_checker.c \
              map_reader.c \
              floodfill.c \
              gnl/get_next_line.c \
              gnl/get_next_line_utils.c \
			  move_physics.c


OBJS        = $(SRCS:.c=.o)

all: mlx $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

mlx:
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -C $(MLX_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(PRINTF_DIR)
	if [ -d "$(MLX_DIR)" ]; then make clean -C $(MLX_DIR); fi

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)


re: fclean all

.PHONY: all clean fclean re mlx
