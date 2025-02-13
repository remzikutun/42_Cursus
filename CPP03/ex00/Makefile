NAME = ClapTrap

SRC = main.cpp \
	  ClapTrap.cpp

OBJ = build/main.o \
      build/ClapTrap.o

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf
OBJ_DIR = build

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	@echo "Creating directory $(OBJ_DIR)"
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
