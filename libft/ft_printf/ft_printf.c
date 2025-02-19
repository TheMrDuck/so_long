/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:33 by aswedan           #+#    #+#             */
/*   Updated: 2024/10/15 10:49:33 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string_format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, string_format);
	while (*string_format)
	{
		if (*string_format == '%')
			ft_format_specifier(++string_format, args, &counter);
		else
		{
			counter += write(1, string_format, 1);
		}
		string_format++;
	}
	va_end(args);
	return (counter);
}

// int	main()
// {
// 	ft_printf("");
// }
