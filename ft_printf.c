#include "ft_printf.h"

int	format(char type)
{
	if (type == '%')
	{
		return (1);
	}
	return (0);
}

int	ft_print_arg(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
	{
		count += ft_putchar(va_arg(args,int));
	}
	else if (format == '%')
	{
		count += ft_putchar(format);
	}
	else if (format == 's')
	{
		count += ft_putstr(va_arg(args,const char *));
	}
	else if (format == 'd' || format == 'i')
	{
		count += ft_putnbr(va_arg(args,int));
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int	count;

	i = 0;
	count = 0;
	va_list args;
	va_start(args,str);
	while (str[i])
	{
		if (format(str[i]) && i < ft_strlen(str))
		{
			i++;
			count += ft_print_arg(str[i],args);
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