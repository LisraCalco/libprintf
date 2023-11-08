/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:24 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/08 16:09:22 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, int isUpper)
{
	int		count;
	char	*base;

	count = 0;
	if (isUpper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_print_hex(n / 16, isUpper);
		count += ft_print_hex(n % 16, isUpper);
	}
	else
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}

int	process_pointer_hex( const char str, va_list ap)
{
	unsigned long	arg_int;
	int				count;

	count = 0;
	if (str == 'p')
	{
		arg_int = va_arg(ap, unsigned long);
		if (arg_int == 0)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		write(1, "0x", 2);
		count = count + 2 + ft_print_hex(arg_int, 0);
	}
	return (count);
}
