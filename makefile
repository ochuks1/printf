CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89
OBJS = main.c print_functions.c utils.c
TEST_OBJ = test_main.c

all: $(OBJS)
    $(CC) $(CFLAGS) -o printf $(OBJS)

test: $(OBJS) $(TEST_OBJ)
    $(CC) $(CFLAGS) -o test_printf $(OBJS) $(TEST_OBJ)

clean:
    rm -f printf test_printf
