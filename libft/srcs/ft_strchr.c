#include "libft.h"

/*The strchr() function takes two arguments:
	str and ch. It searches for the character
	ch in the string pointed to by str*/

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (ch == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
