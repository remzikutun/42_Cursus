NAME = push_swap

B_NAME = checker

LIBFT = libft

LIBFTM = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RED	=	\033[1;31m
GREEN  =	\033[0;32m
NO_COLOR	=	\033[0m

SRCS = 	container_index.c \
			control.c \
			push_b_operation.c \
			push_swap_utils.c \
			push_swap.c \
			rules.c \
			all_rules.c \
			sa_sort_utils.c \
			sb_sort_utils.c \
			stack_operations.c

B_SRCS = checker.c \
			get_next_line_utils.c \
			push_swap_utils.c \
			stack_operations.c \
			container_index.c \
			rules.c \
			all_rules.c \
			control.c \
			checker_utils.c

OBJS = $(SRCS:.c=.o)

B_OBJ = $(B_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS)  $(LIBFTM) -o $(NAME)
	@echo "$(GREEN)The push_swap program was created successfully.$(NO_COLOR)"

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(B_OBJ) $(LIBFTM) -o $(B_NAME)
	@echo "$(GREEN)The Checker program was successfully created.$(NO_COLOR)"

.c.o:
	@$(CC) $(CFLAGS) $< -o $@ -c

clean:
	@rm -f $(OBJS) $(B_OBJ)
	@make clean -C $(LIBFT)
	@echo "$(RED)Push_swap object files have been successfully deleted.$(NO_COLOR)"

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME) $(B_NAME)
	@echo "$(RED)The push_swap program was successfully deleted.$(NO_COLOR)"

re: fclean all

.PHONY: clean fclean re all