/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:18 by aswedan           #+#    #+#             */
/*   Updated: 2024/10/15 10:49:18 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_specifier(const char *string_format,
			va_list args, int *counter)
{
	if (*string_format == 'c')
		*(counter) += ft_putchar(va_arg(args, int));
	if (*string_format == 's')
		*(counter) += ft_putstr(va_arg(args, char *));
	if (*string_format == 'p' || *string_format == 'x' || *string_format == 'X')
		check_hexa(string_format, args, counter);
	if (*string_format == 'd' || *string_format == 'i')
		ft_putnbr(va_arg(args, int), counter);
	if (*string_format == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int), counter);
	if (*string_format == '%')
		*(counter) += write(1, "%", 1);
}
