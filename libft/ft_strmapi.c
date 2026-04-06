/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:58 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/06 23:15:59 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copia;
	int		i;

	if (!s)
	{
		return (NULL);
	}
	copia = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copia)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		copia[i] = f(i, s[i]);
		i++;
	}
	copia[i] = '\0';
	return (copia);
}
