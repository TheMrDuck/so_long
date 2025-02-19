/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:36 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/18 15:29:52 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	error_escaper(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int main(int ac, char **av)
{
	t_gelements	game_elements;

	if (ac != 2 || !(av[1]))
		error_escaper("Error\n Not enough arguments!\n");
	map_parser(av[1], &game_elements);
	return (0);
}
