/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:16:08 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:16:09 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
