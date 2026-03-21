#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*chr;
	char	*src;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		ft_strdup("");
	chr = (char *)s + start;
	if (ft_strlen(chr) < len)
	{
		len_s = ft_strlen(chr) + 1;
	}
	else
	{
		len_s = len + 1;
	}
	src = malloc(sizeof(char) * len_s);
	if (!src)
	{
		return (NULL);
	}
	ft_strlcpy(src, chr, len_s);
	return (src);
}
