/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:47 by aswedan           #+#    #+#             */
/*   Updated: 2024/10/15 10:49:47 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_format_specifier(const char *string_format,
			va_list args, int *counter);
void	check_hexa(const char *format, va_list args, int *counter);
void	ft_put_unsigned_nbr(unsigned int n, int *counter);
int		ft_putchar(char c);
void	ft_putnbr(int n, int *counter);
int		ft_putstr(char *str);
int		ft_printf(const char *string_format, ...);

#endif
