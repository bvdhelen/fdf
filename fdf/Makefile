# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 11:13:21 by eldiaz-c          #+#    #+#              #
#    Updated: 2025/08/06 11:13:21 by eldiaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del archivo de la biblioteca
NAME = fdf

# Compilador y banderas de compilación
CC = cc
FLAGS_1 = -Wall -Werror -Wextra -g
FLAGS_2 = -Imlx_linux -O3

# Linkeo
LINK = -L../mlx_linux -l:libmlx.a -lXext -lX11 -lm -lz

# Rutas de bibliotecas auxiliares
LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf/
GET_NEXT_LINE_DIR = get_next_line/

# Archivo de encabezado / Inclusión de las bibliotecas
# -L ./libft sirve para decirle donde buscar la biblioteca
# -lft = libft.a sirve para indicar que biblioteca enlazar
INCLUDE_LIBFT = -L ./libft -lft
INCLUDE_FT_PRINTF = -L ./ft_printf -lftprintf
INCLUDE_GET_NEXT_LINE = -L ./get_next_line -l:get_next_line.a
INCLUDE_MLX = -Lmlx_linux -lmlx

# Definir códigos de color
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN =  \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Archivos fuente y archivos objeto
SRC = 	alloc_matrices.c \
		centered.c \
		color.c \
		draw.c \
		free.c \
		controls.c \
		init.c \
		main.c \
		menu.c \
		projections.c \
		rasterization.c \
		read_file.c \
		utils.c \
		width_and_height.c \

OBJ = $(SRC:.c=.o)

# Regla para crear los archivos objeto (.o)
# -c indica que se debe commpilar el código sin enlazar (crear solo el .o)
# $< representa el archivo de entrada (el .c que se está compilando)
# -o $@ especifica el nombre del archivo de salida que se está generando
.c.o:
	$(CC) $(FLAGS_1) $(FLAGS_2) -c $< -o $@

# Regla para compilar fdf con libft, ft_printf y get_next_line
# -C sirve para cambiar UNA VEZ al directorio especificado antes de ejecutar el Makefile
$(NAME): header $(OBJ)
	@make -C $(LIBFT_DIR) --no-print-directory
	@make -C $(FT_PRINTF_DIR) --no-print-directory
	@make -C $(GET_NEXT_LINE_DIR) --no-print-directory
	@$(CC) $(FLAGS_1) $(FLAGS_2) $(OBJ) -o $(NAME) \
		$(LINK) \
		$(INCLUDE_MLX) \
		$(INCLUDE_LIBFT) \
		$(INCLUDE_FT_PRINTF) \
		$(INCLUDE_GET_NEXT_LINE)
	@echo
	@echo "$(GREEN)<<< fdf compiled >>>$(RESET)"
	@echo

# Regla principal que lo compila todo
all: $(NAME)

# Eliminar todos los archivos .o y .a
clean:
	@rm -f $(OBJ) */*.o
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) clean -C $(FT_PRINTF_DIR) --no-print-directory
	@$(MAKE) clean -C $(GET_NEXT_LINE_DIR) --no-print-directory
	@echo
	@echo "$(CYAN)<<< CLEAN COMPLETE >>>$(RESET)"
	@echo

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) fclean -C $(FT_PRINTF_DIR) --no-print-directory
	@$(MAKE) fclean -C $(GET_NEXT_LINE_DIR) --no-print-directory
	@echo "$(BLUE)<<< FULL CLEAN COMPLETE >>>$(RESET)"
	@echo

re: fclean all

norminette:
	@norminette || true
	@echo
	@echo "$(GREEN)<<< norminette check OK >>>$(RESET)"
	@echo

# ASCII Art
header:
	@echo
	@echo " $(MAGENTA)                  ____    ______         "
	@echo " $(MAGENTA)                 / __/___/ / __/         "
	@echo " $(MAGENTA)                / /_/ __  / /_           "
	@echo " $(MAGENTA)               / __/ /_/ / __/           "
	@echo " $(MAGENTA)              /_/  \__,_/_/           __ "
	@echo " $(MAGENTA)    ____  _________  __  _____  _____/ /_"
	@echo " $(MAGENTA)   / __ \/ ___/ __ \/ / / / _ \/ ___/ __/"
	@echo " $(MAGENTA)  / /_/ / /  / /_/ / /_/ /  __/ /__/ /_  "
	@echo " $(MAGENTA) / .___/_/   \____/\__, /\___/\___/\__/  "
	@echo " $(MAGENTA)/_/               /____/                 "
	@echo " $(WHITE) "
	@echo

# Indica que las siguientes reglas no son archivos reales
.PHONY: all clean fclean re norminette header
