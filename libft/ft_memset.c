/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:15:06 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memset() function takes three arguments:
dest, ch and count. The character represented by ch
is first converted to unsigned char and then copies
it into the first count characters of the object pointed to by dest.*/

void	ft_memset(void *dest, int ch, size_t count)
{
	unsigned char	*ps;
	int				i;

	ps = (unsigned char *)dest;
	i = 0;
	if (count == 0)
	{
		return ;
	}
	while (count != 0)
	{
		ps[i] = ch;
		count--;
		i++;
	}
}
