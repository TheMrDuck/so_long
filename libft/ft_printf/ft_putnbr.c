/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:50:08 by aswedan           #+#    #+#             */
/*   Updated: 2024/10/15 10:50:08 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
	{
		*(counter) += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*(counter) += write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
	if (n <= 9)
		*(counter) += ft_putchar(n + 48);
}
