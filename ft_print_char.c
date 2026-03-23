#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i] )
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
