#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (format(str[i]) && i < ft_strlen(str))
		{
			i++;
			count += ft_print_arg(str[i], args);
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
