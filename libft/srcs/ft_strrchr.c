#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	size_t			ch;
	unsigned char	carater;
	char			*cpy;

	ch = ft_strlen(str);
	cpy = (char *)str + ch;
	carater = chr;
	if (carater == '\0')
	{
		return (cpy++);
	}
	while (cpy >= str)
	{
		if (*cpy == carater)
		{
			return (cpy);
		}
		cpy--;
	}
	return (NULL);
}
