CCFLAGS := -Wextra -Wall -Werror
NAME := libft.a
SRC = \
	ft_isalpha.c\
	ft_isdigit.c\
	ft_memcpy.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strchr.c\
	ft_tolower.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_memset.c\
	ft_strlcpy.c\
	ft_memmove.c\
	ft_strlcat.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstdelone.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

INCLUDES := includes/
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): all
.c.o:
	cc $(CCFLAGS) -c -I$(INCLUDES) $< -o $(<:.c=.o)

libft.a: $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean rev