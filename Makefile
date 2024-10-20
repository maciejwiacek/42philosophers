NAME = philo

SRC_DIR = src

SRC_FILES = main.c \
			utils.c \
			validate.c \
			atol.c \
			init.c \
			dinner.c \
			philo_actions.c \
			monitoring_utils.c

SRC = $(foreach file,$(SRC_FILES),$(SRC_DIR)/$(file))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re