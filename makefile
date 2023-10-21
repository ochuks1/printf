CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = _printf.c task_0.c task_1.c
OBJ = $(SRC:.c=.o)
NAME = libprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
