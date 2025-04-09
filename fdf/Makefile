NAME = fdf

CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = *.c

INCLUDES = ../libmlx.a

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME)
