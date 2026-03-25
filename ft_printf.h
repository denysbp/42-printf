#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nbr);
int	ft_put_unsigned_nbr(unsigned int nbr);
int	print_ptr(void *ptr);
int	ft_puthex(unsigned long nbr, int uppercase);
int	ft_print_arg(char format, va_list args);
int	format(char type);

#endif