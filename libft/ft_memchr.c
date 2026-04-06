/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:14:50 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:14:51 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t size)
{
	unsigned char	*carater;
	unsigned char	ch;

	ch = chr;
	carater = (unsigned char *)str;
	while (size != 0)
	{
		if (*carater == ch)
		{
			return ((char *)carater);
		}
		carater++;
		size--;
	}
	return (NULL);
}
