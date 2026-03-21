#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	int				i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char *)str;
	while (n != 0)
	{
		st[i] = '\0';
		n--;
		i++;
	}
}
