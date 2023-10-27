CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = mi_programa
SRC_DIR = Sources
INC_DIR = Includes
SRC_FILES = ft_args_checker.c ft_error.c ft_printf.c main.c main_bonus.c putnbr_base_fd.c putptr_fd.c putstr_fd.c
INC_FILES = ft_printf.h
OBJ_DIR = obj

# Construye la lista de rutas de archivos de origen y objetos
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Regla predeterminada
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar los archivos fuente en objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
