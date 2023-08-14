NAME = so_long

CC = gcc

CFLAGS = 	-Wall -Wextra -Werror -Iheaders/

SOURCE = 	so_long.c \
			controls/pre_controls.c \
			read_map/read_map.c

LIBRARY = -L./mlx -lmlx -framework OpenGL -framework AppKit
MINILIBX = mlx/

all:
	make -C $(MINILIBX)
	@$(CC) $(CFLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

clean:
	make clean -C $(MINILIBX)

fclean: clean	
	rm -rf $(NAME)

re: clean fclean all