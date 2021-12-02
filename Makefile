NAME = so_long
FLAGS = -Wall -Werror -Werror
SRC = src/main.c\
	src/utils.c\
	src/init.c\
	src/actions.c\
	src/print_map.c\
	src/gnl/get_next_line.c\
	src/gnl/get_next_line_utils.c
INC = inc/header.h\
	inc/keysymdef.h
LIB = -L ./mlx -lmlx -lXext -lX11

all : $(NAME)

$(NAME):
	cd mlx/ && ./configure
	gcc -g -g3 -o $(NAME) $(SRC) $(LIB)

clean:
	rm -rf *.o

fclean: clean
	rm $(NAME)

re: fclean all
