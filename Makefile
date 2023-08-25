NAME	=	so_long
CFLAGS	=	-Wall -Wextra -Werror -I./mlx -g

LFLAGS	=	-framework AppKit -framework OpenGL -L./mlx -lmlx -fsanitize=address
MLX		=	./mlx/libmlx.a

LIBFT	=	./libft

GNL		=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c 

PRINTF	=	./ft_printf

SRCS	=	so_long.c \
			controls/pre_controls.c \
			controls/map_controls.c \
			controls/flood_fill.c \
			controls/map_controls_1.c \
			read_map/read_map.c \
			window/key_control.c \
			window/clear_win.c \
			window/put_textures.c \
			animation/animate_coin.c \

OBJS	=	$(SRCS:.c=.o)
GNLOBJS	=	$(GNL:.c=.o)

all : $(MLX) $(NAME)

$(MLX):
	make -C $(PRINTF)
	make bonus -sC LIBFT
	make -sC ./mlx

$(NAME): $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)
	rm -rf ./mlx/*.o
	rm -rf ./gnl/*.o

fclean: clean
	make clean -C ./mlx
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY: so_long clean fclean re