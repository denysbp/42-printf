/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:16:17 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:16:18 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*chr;
	char	*src;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
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
