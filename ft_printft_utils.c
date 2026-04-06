/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:20:06 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/07 00:20:07 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char type)
{
	if (type == '%')
	{
		return (1);
	}
	return (0);
}

int	ft_print_arg(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == '%')
		count += ft_putchar(format);
	else if (format == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		count += print_ptr(va_arg(args, void *));
	return (count);
}
