NAME = libftprintf.a
CC	= gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_funcs.c ft_printf.c printf_utils.c type_check.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all