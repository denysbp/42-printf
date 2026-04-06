/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:16:04 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:16:05 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*src == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < size)
	{
		j = 0;
		while ((i + j) < size && str[i + j] == src[j])
		{
			if (src[j + 1] == '\0')
			{
				return ((char *)(str + i));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
