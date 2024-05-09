NAME = philo

INC = includes

CC = gcc
FLAGS = -Wall -Wextra -Werror #-pthread -fsanitize=thread -g
RM = rm -rf

SRCS =  sources/destroy.c sources/error_states.c sources/initialization.c sources/lock_unlock.c \
		sources/main.c sources/param_control.c sources/printing.c sources/start_dinner.c \
		sources/timers.c sources/utils.c

OBJS = $(SRCS:.c=.o)

RED	=	\033[1;31m
GREEN  =	\033[0;32m
ORANGE = \033[38;5;208m
NO_COLOR	=	\033[0m


all: $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN)🟢 The philo program was created successfully.$(NO_COLOR)"

.c.o:
		@$(CC) $(CFLAGS) $< -o $@ -c

clean:
		@$(RM) $(OBJS)
		@echo "$(ORANGE)🟠 The philo object files have been successfully deleted.$(NO_COLOR)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED)🔴 The philo program was successfully deleted.$(NO_COLOR)"

re: fclean all

norm:
		@norminette $(SRCS) $(INC)

.PHONY: all clean fclean re norm