NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = mlx

RED	=	\033[1;31m
GREEN  =	\033[0;32m
NO_COLOR	=	\033[0m

SRCS = source/main.c source/file_saving.c source/extension_check.c \
		source/map_control.c source/start_game.c source/motion_control.c \
		source/free.c source/pathfinding.c

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MLX_PATH)/libmlx.a
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(MLX_PATH)/libmlx.a -framework OpenGL -framework AppKit
	@echo "$(GREEN)The so_long program was created successfully.$(NO_COLOR)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) all

$(MLX_PATH)/libmlx.a:
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "$(RED)SO_LONG, LIBFT and MLX object files have been successfully deleted.$(NO_COLOR)"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "$(RED)The SO_LONG program was successfully deleted.$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
