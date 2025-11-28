# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 09:54:52 by fgarnier          #+#    #+#              #
#    Updated: 2025/11/28 09:58:24 by fgarnier         ###   ########.fr        #
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
              load_texture.c \
              unload_texture.c \
              apply_texture.c \
              apply_texture_wall.c \
              apply_texture_diagonal.c \
              map_checker.c \
              map_reader.c \
              floodfill.c \
              gnl/get_next_line.c \
              gnl/get_next_line_utils.c


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
