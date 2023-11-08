/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:43:28 by tlegendr          #+#    #+#             */
/*   Updated: 2023/11/08 16:13:05 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_nbr_unsigned(unsigned long n);
int	ft_print_nbr(int nb);
int	process_large_arg( const char str, va_list ap);
int	parse_arg(const char str, va_list ap);
int	process_pointer_hex( const char str, va_list ap);
int	ft_print_hex(unsigned long n, int isUpper);

#endif