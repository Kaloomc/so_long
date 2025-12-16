# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 09:54:52 by fgarnier          #+#    #+#              #
#    Updated: 2025/12/16 23:48:10 by fgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME        = so_long

# Compilateur et Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

# Dossiers
OBJ_DIR     = obj
MLX_DIR     = mlx
PRINTF_DIR  = ft_printf
GNL_DIR     = gnl

# Bibliothèques
MLX_LIB     = $(MLX_DIR)/libmlx.a
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

# Inclusions et Linkage
INC         = -I. -I$(MLX_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Sources
SRCS        = so_long.c \
              main_loop.c \
              load.c \
              load_texture.c \
              load_texture2.c \
			  load_animation.c \
              unload.c \
              unload_texture.c \
			  unload_animation.c \
              apply_texture.c \
              get_texture_wall.c \
              get_texture_wall2.c \
              get_texture_wall3.c \
              map_checker.c \
              map_reader.c \
              floodfill.c \
              move_physics.c \
			  get_key.c \
			  coin.c \
			  enemy_logic.c \
			  load_enemy.c \
			  enemy_renderer.c \
			  hud.c \
			  enemy_update.c \
			  player_logic.c \
              $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

# Objets
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# **************************************************************************** #
#                                COULEURS & PIXELS                             #
# **************************************************************************** #

RESET   = \033[0m
C_GREEN = \033[0;92m
C_CYAN  = \033[0;96m
C_BLUE  = \033[0;94m
C_GREY  = \033[0;90m

# Palette du Pirate (Mapping XPM vers ANSI)
# . = K (Black/Dark)
# X = P (Purple)
# o = B (Blue/Grey)
# O = W (White)
# + = R (Red)
# @ = L (Light Red/Rosy)
# # = O (Orange)
# $ = Y (Yellow)
# % = S (Skin/Beige)
# & = G (Gold)

_K = \033[38;5;235m■
_P = \033[38;5;55m■
_B = \033[38;5;67m■
_W = \033[38;5;231m■
_R = \033[38;5;160m■
_L = \033[38;5;131m■
_O = \033[38;5;216m■
_Y = \033[38;5;220m■
_S = \033[38;5;223m■
_G = \033[38;5;178m■

# **************************************************************************** #
#                                REGLES                                        #
# **************************************************************************** #

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo ""
	@echo "$(C_CYAN)  ██████  ██████      ██       ██████  ███    ██  ██████ "
	@echo "$(C_CYAN) ██       ██  ██      ██       ██  ██  ████   ██  ██     "
	@echo "$(C_CYAN)  ██████  ██  ██      ██       ██  ██  ██ ██  ██  ██   ███"
	@echo "$(C_CYAN)       ██ ██  ██      ██       ██  ██  ██  ██ ██  ██    ██"
	@echo "$(C_CYAN)  ██████  ██████      ██████   ██████  ██   ████   ██████ "
	@echo "$(RESET)"
	@echo "        $(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)        "
	@echo "       $(_K)$(_P)$(_P)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_K)       "
	@echo "      $(_K)$(_P)$(_P)$(_B)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_B)$(_B)$(_K)      "
	@echo "      $(_K)$(_P)$(_P)$(_K)$(_W)$(_W)$(_W)$(_W)$(_W)$(_W)$(_W)$(_K)$(_B)$(_K)      "
	@echo "      $(_K)$(_P)$(_P)$(_K)$(_W)$(_K)$(_K)$(_W)$(_K)$(_K)$(_W)$(_K)$(_B)$(_K)      "
	@echo "      $(_K)$(_P)$(_P)$(_B)$(_K)$(_W)$(_W)$(_W)$(_W)$(_W)$(_K)$(_B)$(_B)$(_K)      "
	@echo "      $(_K)$(_P)$(_P)$(_B)$(_K)$(_W)$(_K)$(_W)$(_K)$(_W)$(_K)$(_B)$(_B)$(_K)      "
	@echo " $(_K)$(_K)$(_K) $(_K)$(_P)$(_P)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_K) $(_K)$(_K)$(_K) "
	@echo "$(_K)$(_B)$(_B)$(_K) $(_K)$(_P)$(_P)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_K) $(_K)$(_B)$(_B)$(_K)"
	@echo "$(_K)$(_B)$(_K)$(_K)$(_K)$(_K)$(_K)$(_P)$(_P)$(_P)$(_B)$(_B)$(_B)$(_B)$(_B)$(_P)$(_B)$(_P)$(_P)$(_K)$(_K)$(_K)$(_B)$(_K)"
	@echo "$(_K)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_B)$(_K)"
	@echo " $(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K) "
	@echo "    $(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_R)$(_R)$(_R)$(_R)$(_R)$(_K)$(_K)$(_K)$(_K)    "
	@echo "    $(_K)$(_L)$(_K)$(_W)$(_W)$(_K)$(_R)$(_Y)$(_Y)$(_Y)$(_Y)$(_Y)$(_Y)$(_K)$(_L)$(_K)    "
	@echo "    $(_K)$(_L)$(_K)$(_K)$(_K)$(_K)$(_R)$(_Y)$(_Y)$(_S)$(_S)$(_Y)$(_Y)$(_K)$(_S)$(_K)    "
	@echo "   $(_K)$(_K)$(_L)$(_L)$(_K)$(_K)$(_K)$(_K)$(_K)$(_S)$(_S)$(_S)$(_K)$(_K)$(_K)   "
	@echo "  $(_K)$(_R)$(_R)$(_K)$(_L)$(_L)$(_L)$(_L)$(_S)$(_S)$(_S)$(_S)$(_S)$(_S)$(_S)$(_S)$(_K)$(_K)$(_K)  "
	@echo " $(_K)$(_O)$(_O)$(_O)$(_R)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_K)$(_R)$(_K)$(_R)$(_K) "
	@echo ""
	@echo "$(C_GREEN)   >>> Pirate Ready to Sail! <<<   $(RESET)"

# Compilation des objets
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(C_GREY)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Libftprintf
$(PRINTF_LIB):
	@echo "$(C_BLUE)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) > /dev/null

# MinilibX
$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "$(C_GREY)MinilibX not found, downloading...$(RESET)"; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@echo "$(C_BLUE)Compiling MinilibX...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(PRINTF_DIR) > /dev/null
	@if [ -d "$(MLX_DIR)" ]; then make clean -C $(MLX_DIR) > /dev/null; fi
	@echo "$(C_GREY)Objects removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR) > /dev/null
	@echo "$(C_GREY)Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re mlx