#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
	}
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}