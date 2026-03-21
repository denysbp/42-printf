#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*pbr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
	{
		return (NULL);
	}
	total = nmemb * size;
	pbr = malloc(total);
	if (pbr == NULL)
	{
		return (NULL);
	}
	ft_memset(pbr, 0, total);
	return (pbr);
}
