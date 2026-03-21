#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;

	if (src == NULL)
	{
		return (NULL);
	}
	dup = (char *)malloc(ft_strlen(src) + 1);
	ft_strlcpy(dup, src, sizeof(src));
	return (dup);
}
