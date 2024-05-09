NAME	=	libft.a

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f

RED	=	\033[1;31m
GREEN  =	\033[0;32m
NO_COLOR	=	\033[0m

SRCS	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_memchr.c ft_memcmp.c ft_striteri.c ft_memcpy.c ft_memmove.c\
ft_memset.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
ft_strchr.c ft_strlcpy.c ft_strmapi.c ft_strdup.c ft_split.c ft_calloc.c ft_itoa.c\
ft_strlen.c ft_strncmp.c ft_substr.c ft_strtrim.c ft_strnstr.c ft_strrchr.c\
ft_strjoin.c ft_tolower.c ft_toupper.c ft_strlcat.c

B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ	= $(SRCS:.c=.o)
B_OBJ =	$(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)The libft library has been successfully compiled.$(NO_COLOR)"

bonus: $(B_OBJ)
	@ar rcs $(NAME) $(B_OBJ)
	@echo "$(GREEN)The libft bonus library has been successfully compiled.$(NO_COLOR)"

.c.o:
	@$(CC) $(CFLAGS) $< -o $@ -c
	
clean:
	@$(RM) $(OBJ) $(B_OBJ)
	@echo "$(RED)LIBFT object files have been successfully deleted.$(NO_COLOR)"


fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)The libft.a archive was successfully deleted.$(NO_COLOR)"

re:	fclean $(NAME)

.PHONY: all clean fclean re