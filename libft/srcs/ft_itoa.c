#include "libft.h"

int	get_digits(int n)
{
	int	digits;
	int	copia;

	copia = n;
	digits = 0;
	if (n <= 0)
	{
		digits++;
	}
	while (copia)
	{
		copia /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	long	copia;
	char	*numero;

	digits = get_digits(n);
	copia = n;
	numero = malloc(sizeof(char) * (digits + 1));
	if (!numero)
		return (NULL);
	numero[digits] = '\0';
	if (copia < 0)
	{
		copia = -copia;
		numero[0] = '-';
	}
	if (copia == 0)
		numero[0] = '0';
	while (copia)
	{
		numero[--digits] = (copia % 10) + '0';
		copia /= 10;
	}
	return (numero);
}
