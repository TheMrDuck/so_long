/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_dealer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:28 by aswedan           #+#    #+#             */
/*   Updated: 2024/10/15 10:49:28 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upper_hexa(unsigned int n, int *counter);
void	ft_lower_hexa(unsigned long long n, int *counter);

void	check_hexa(const char *format, va_list args, int *counter)
{
	unsigned long long int	i;

	if (*format == 'p')
	{
		i = va_arg(args, unsigned long long);
		if (i == 0)
		{
			*(counter) += write(1, "(nil)", 5);
			return ;
		}
		*(counter) += write (1, "0x", 2);
		ft_lower_hexa (i, counter);
	}
	if (*format == 'x')
		ft_lower_hexa (va_arg(args, unsigned int), counter);
	if (*format == 'X')
		ft_upper_hexa (va_arg(args, unsigned int), counter);
	(void) i;
}

void	ft_upper_hexa(unsigned int n, int *counter)
{
	if (n >= 16)
		ft_upper_hexa(n / 16, counter);
	*(counter) += ft_putchar("0123456789ABCDEF"[n % 16]);
}

void	ft_lower_hexa(unsigned long long n, int *counter)
{
	if (n >= 16)
		ft_lower_hexa(n / 16, counter);
	*(counter) += ft_putchar("0123456789abcdef"[n % 16]);
}
