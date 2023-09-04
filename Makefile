NAME	=	so_long
CFLAGS	=	-Wall -Wextra -Werror -I./mlx -g
CC		= 	gcc
LFLAGS	=	-framework AppKit -framework OpenGL -L./mlx -lmlx
LIB		=	./mlx/libmlx.a

LIBFT	=	./libft

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
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c 

OBJS	=	$(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a ./ft_printf/libftprintf.a $(LFLAGS) -o $(NAME)

$(LIB): 
	make -C $(PRINTF)
	make -C $(LIBFT)
	make -C ./mlx

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

.PHONY: all clean fclean re
