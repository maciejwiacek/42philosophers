NAME = philo

SRC_DIR = src

SRC_FILES = main.c \

SRC = $(foreach file,$(SRC_FILES),$(SRC_DIR)/$(file))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -C library
	cc -Wall -Wextra -Werror $(OBJ) library/library.a -o $(NAME)

clean:
	make clean -C library
	rm -f $(OBJ)

fclean: clean
	make fclean -C library
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re