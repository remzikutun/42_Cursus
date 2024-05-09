C_NAME = client
S_NAME = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

C_SRC = client.c
S_SRC = server.c
C_BONUS_SRC = client_bonus.c
S_BONUS_SRC = server_bonus.c

S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)
S_BONUS_OBJ = $(S_BONUS_SRC:.c=.o)
C_BONUS_OBJ = $(C_BONUS_SRC:.c=.o)

BOLD_YELLOW	=	\033[1;33m
BOLD_GREEN  =	\033[0;32m
NO_COLOR	=	\033[0m

all: server client

bonus: server_bonus client_bonus

server: $(S_OBJ)
	@$(CC) $(CFLAGS) $(S_OBJ) -o $(S_NAME)
	@echo "Compilation completed, server created.$(BOLD_GREEN) Server Ready!!!"

client: $(C_OBJ)
	@$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME)
	@echo "$(NO_COLOR)Compilation completed, client created.$(BOLD_GREEN) Client Ready!!!$(NO_COLOR)"

server_bonus: $(S_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(S_BONUS_OBJ) -o $(S_NAME)
	@echo "Compilation completed, server created.$(BOLD_GREEN) Server Ready!!!"

client_bonus: $(C_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(C_BONUS_OBJ) -o $(C_NAME)
	@echo "$(NO_COLOR)Compilation completed, client created.$(BOLD_GREEN) Client Ready!!!$(NO_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(S_OBJ) $(C_OBJ) $(S_BONUS_OBJ) $(C_BONUS_OBJ)
	@echo "$(BOLD_YELLOW)Clean:$(NO_COLOR)The object files have been deleted."

fclean: clean
	@$(RM) $(C_NAME) $(S_NAME)
	@echo "$(BOLD_YELLOW)Fclean:$(NO_COLOR)The Server and Client files have been deleted."

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus bonus re_bonus