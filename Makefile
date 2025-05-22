NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -Ilibft
SRC     = $(filter-out main.c, $(wildcard *.c))
OBJ = $(SRC:.c=.o)
HEADER = libft/libft.h
LIBFT_SRC = $(wildcard libft/*.c)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJ) $(LIBFT_OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean : clean	
	rm -f $(NAME) test

re: fclean all

test : $(NAME) main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) main.c $(NAME) -o test

.PHONY: all clean fclean re test

