NAME = push_swap

SRCS = $(wildcard libft/*.c rules/*.c sort/*.c check_error/*.c utils/*.c main.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft re
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	@make -C ./libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re