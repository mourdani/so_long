NAME = so_long

CC = gcc

FLAGS = -Wall -Werror -Werror

MLX = mlx/Makefile.gen

LIB = -L ./mlx -lmlx -lXext -lX11

INC = -I ./inc/ -I ./mlx


SRC =	src/main.c\
	src/utils.c\
	src/init.c\
	src/moves.c\
	src/errors.c\
	src/actions.c\
	src/print_map.c\
	src/get_next_line.c\
	src/get_next_line_utils.c

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

all : $(MLX) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
	Make -s -C mlx

obj:
	mkdir -p obj

obj/%.o: src/%.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

norm:
	norminette inc src

clean:
	rm -rf $(OBJ) obj

fclean: clean
	rm $(NAME)

re: fclean all
