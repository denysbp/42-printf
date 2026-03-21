#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t size)
{
	unsigned char	*carater;
	unsigned char	ch;

	ch = chr;
	carater = (unsigned char *)str;
	while (size != 0)
	{
		if (*carater == ch)
		{
			return ((char *)carater);
		}
		carater++;
		size--;
	}
	return (NULL);
}
