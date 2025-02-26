/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:52:03 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/09 14:54:28 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	c;

	c = 0;
	if (!s || !f)
		return ;
	while (s[c])
	{
		f(c, &s[c]);
		c++;
	}
}
