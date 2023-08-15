NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I./minilibx -g

LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a

LIBFT = -I./libft
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)

SRCS = so_long.c \
		controls/pre_controls.c \
		read_map/read_map.c \

OBJS = $(SRCS:.c=.o)

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -sC LIBFT
	make -sC ./mlx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a  -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf ./gnl/*.o
	make clean -C ./libft

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./gnl/*.o
	make clean -C ./mlx
	make fclean -C ./libft

re : fclean all

.PHONY: clean fclean re