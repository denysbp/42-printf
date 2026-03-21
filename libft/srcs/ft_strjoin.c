#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (! s1 || ! s2)
	{
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (! str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s1, sizeof(s1));
	ft_strlcat(str, s2, sizeof(s2));
	return (str);
}
