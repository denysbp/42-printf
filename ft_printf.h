#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nbr);


#endif