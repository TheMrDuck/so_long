/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:17:40 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/22 15:25:49 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	other_elements_validator(t_gelements *game_elements)
{
	int	i;
	int	j;

	i = -1;
	game_elements -> player = 0;
	game_elements -> collectable = 0;
	game_elements -> exit = 0;
	while (game_elements -> map[++i])
	{
		j = -1;
		while (game_elements -> map[i][++j])
		{
			if (game_elements -> map[i][j] == 'P')
				game_elements -> player++;
			else if (game_elements -> map[i][j] == 'C')
				game_elements -> collectable++;
			else if (game_elements -> map[i][j] == 'E')
				game_elements -> exit++;
		}
	}
	if (game_elements -> player != 1 || game_elements -> collectable < 1 \
	|| game_elements -> exit != 1)
		error_escaper("Error\nWrong number of player or collectable or exit!\n");
}

void	newline_remover(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	map_freeing(t_gelements *game_elements, char *msg)
{
	write(2, msg, ft_strlen(msg));
	free_2d(game_elements -> map);
	free_2d(game_elements -> dup_map);
	exit(1);
}
