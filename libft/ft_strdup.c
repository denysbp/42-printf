/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:34 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:15:36 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	if (! src)
	{
		return (NULL);
	}
	dup = (char *)malloc(ft_strlen(src) + 1);
	if (! dup)
	{
		return (NULL);
	}
	ft_strlcpy(dup, src, ft_strlen(src) + 1);
	return (dup);
}
