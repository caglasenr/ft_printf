NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c ft_printf_ffonks.c ft_printf_sfonks.c

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re