/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:55 by aswedan           #+#    #+#             */
/*   Updated: 2024/10/15 10:49:55 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(unsigned int n, int *counter)
{
	if (n > 9)
	{
		ft_put_unsigned_nbr(n / 10, counter);
		ft_put_unsigned_nbr(n % 10, counter);
	}
	if (n <= 9)
		*(counter) += ft_putchar(n + '0');
}
