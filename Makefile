# Nom du fichier exécutable final
NAME = push_swap

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Dossiers
SRC_DIR = src
LIBFT_DIR = Libft

# Fichiers sources
SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/utils_1.c $(SRC_DIR)/utils_2.c $(SRC_DIR)/swap.c $(SRC_DIR)/rotate.c $(SRC_DIR)/push.c $(SRC_DIR)/reverse_rotate.c
OBJ = $(SRC:.c=.o)

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règles
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

# Utilisation
# `make`      : Compile tout
# `make clean`: Supprime les fichiers objets
# `make fclean`: Supprime les fichiers objets et l'exécutable
# `make re`   : Recompile tout

