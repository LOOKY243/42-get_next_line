CC=clang
NAME = ft_get_next_line.a
SRCS = ft_get_next_line.c ft_get_next_line_utils.c
HEADER = ft_get_next_line.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

run: all
	./$(NAME)

re: fclean all

.PHONY: all fclean clean run re
