#include "libft.h"

/* This function copies bytes;
it doesn't check for comparisons,
it simply copies the bytes from the source
to the destination up to the requested size.*/

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	int			i;
	char		*pd;
	const char	*ps;

	ps = (const char *)src;
	pd = (char *)dest;
	i = 0;
	if (count == 0 || dest == src)
	{
		return (dest);
	}
	while (count != 0)
	{
		pd[i] = ps[i];
		count--;
		i++;
	}
	return (dest);
}
