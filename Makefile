# Makefile pour so_long sur Linux

# Nom de l'exécutable
NAME = so_long

# Sources
SRC = main.c

# Dossier MLX
MLX_DIR = mlx

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

# Librairies
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Objet
OBJ = $(SRC:.c=.o)

# -------------------------------------------------
# Règles
# -------------------------------------------------

all: mlx $(NAME)

# Compile MLX si elle n'existe pas
mlx:
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -C $(MLX_DIR)

# Compile le projet
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

# Compile les .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
