NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Ilibft
SRC     = ft_arg1.c  ft_arg2.c  \
		ft_hex.c  ft_printf.c ft_uitoa.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME):$(OBJ) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	ar rcs -o $(NAME) $(OBJ)


$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean : clean	
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re

