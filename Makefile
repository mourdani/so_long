NAME = so_long
FLAGS = -Wall -Werror -Werror
SRC = main.c
INC = header.h
LIB = -L ./mlx -lmlx -lXext -lX11

all : $(NAME)

$(NAME):
	cd mlx/ && ./configure
	gcc -g3 -o $(NAME) $(SRC) $(LIB)

clean:
	rm -rf *.o

fclean: clean
	rm $(NAME)

re: fclean all
