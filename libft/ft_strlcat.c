/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:44 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:15:45 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_return(size_t size, size_t len_src, size_t len_dest)
{
	if (len_dest < size)
	{
		return (len_src + len_dest);
	}
	else
	{
		return (size + len_src);
	}
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		len_src;
	size_t		len_dest;

	len_dest = ft_strlen(dest);
	i = 0;
	len_src = ft_strlen(src);
	if (size <= len_dest)
	{
		return (size + len_src);
	}
	while (src[i] != '\0' && len_dest + i < (size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (ft_return(size, len_src, len_dest));
}
