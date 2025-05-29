NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -Ilibft
SRC     = ft_arg1.c  ft_arg2.c  \
		ft_hex.c  ft_printf.c  ft_uitoa.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME):$(OBJ) $(LIBFT_A)
	ar rcs $@ $^


$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean : clean	
	rm -f $(NAME) test
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

test : $(NAME) main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) main.c $(NAME) $(LIBFT_A) -o test


.PHONY: all clean fclean re test

