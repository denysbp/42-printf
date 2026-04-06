/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:19:52 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/07 00:19:53 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nbr, int uppercase)
{
	char	*base;
	int		count;

	count = 0;
	if (uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (nbr >= 16)
	{
		count += ft_puthex((nbr / 16), uppercase);
		count += ft_puthex((nbr % 16), uppercase);
	}
	else
	{
		count += ft_putchar(base[nbr]);
	}
	return (count);
}

int	print_ptr(void *ptr)
{
	int				count;
	unsigned long	nbr;

	nbr = 0;
	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("0x0");
		return (count);
	}
	count += ft_putstr("0x");
	nbr = (unsigned long)ptr;
	count += ft_puthex(nbr, 0);
	return (count);
}
