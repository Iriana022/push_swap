### ARGUMENTS
NAME = push_swap
SRC = src/main.c src/errors.c src/ft_atol.c
CC = cc
CFLAGS = -Wall -Wextra ##-Werror
RM = rm -rf

### RULES

all: $(NAME)

$(NAME): $(SRC)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -Lft_printf -lftprintf

clean:
	make -C ./ft_printf
	$(RM) *.o

fclean: clean
	make -C ./ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
