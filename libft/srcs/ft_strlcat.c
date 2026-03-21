#include "libft.h"

int	char_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		len_src;
	size_t		len_dest;

	len_dest = char_strlen(dest);
	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
	{
		return (len_src);
	}
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[len_dest] = src[i];
		i++;
		len_dest++;
	}
	dest[len_dest] = '\0';
	if (len_dest < size)
	{
		return (len_src + len_dest);/*Tamanho ideal da string final*/
	}
	else
	{
		return (size + len_src);/*dest não cabe no buffer retorno indica truncamento*/
	}
}
