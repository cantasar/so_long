NAME	=	so_long
CFLAGS	=	-Wall -Wextra -Werror -I./minilibx -g

LFLAGS	=	-framework AppKit -framework OpenGL -L./mlx -lmlx
MLX		=	./mlx/libmlx.a

LIBFT	=	-I./libft
GNL		=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c 

SRCS	=	so_long.c \
			controls/pre_controls.c \
			controls/map_controls.c \
			read_map/read_map.c \

OBJS	=	$(SRCS:.c=.o)
GNLOBJS	=	$(GNL:.c=.o)

all : $(MLX) $(NAME)

$(MLX):
	make bonus -sC LIBFT
	make -sC ./mlx

$(NAME): $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a  -o $(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf ./*/*.o

fclean: clean
	rm -rf $(OBJS) $(NAME)
	make clean -C ./mlx
	make fclean -C ./libft
	rm -rf ./*/*.a

re : fclean all

.PHONY: clean fclean re