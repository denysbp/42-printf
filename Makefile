NAME:= libftprintf.a

CCFLAGS = cc -Wextra -Wall -Werror

FILES = \
	ft_printf.c\
	ft_print_char.c\
	ft_print_number.c\
	ft_print_hex.c\
	ft_printf_utils.c\

OBJ = $(FILES:.c=.o)

libft_path = ./libft

libft = $(libft_path)/libft.a

all: $(NAME)


%.o: %.c
	$(CCFLAGS) -c $< -o $@

$(libft):
	make -C $(libft_path) all

$(NAME): $(libft) $(OBJ)
	cp $(libft) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make -C $(libft_path) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(libft_path) fclean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re libft
