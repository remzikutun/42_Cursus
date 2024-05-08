NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
SRC = ft_printf.c ft_printf_base.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -c $(SRC)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f  $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re