/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:16:01 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:16:02 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *st, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 0)
	{
		return (0);
	}
	while (i < count && str[i] == st[i] && str[i] && st[i])
	{
		i++;
	}
	if (i == count)
		return (0);
	return ((unsigned char)str[i] - (unsigned char)st[i]);
}
