/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:10:07 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/19 20:11:25 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_location(t_gelements *game_elements)
{
	int	row;
	int	col;

	row = 0;
	while (game_elements -> map[row])
	{
		col = 0;
		while (game_elements -> map[row][col])
		{
			if (game_elements -> map[row][col] == 'P')
			{
				game_elements -> player_x = row;
				game_elements -> player_y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	map_copier(t_gelements *game_elements)
{
	int	row;

	row = 0;
	game_elements -> dup_map = malloc(sizeof(char *) \
	* (sizeof(game_elements -> map) + 1));
	if (!game_elements -> dup_map)
		error_escaper("Error\nmalloc failed!\n");
	while (game_elements -> map[row])
	{
		game_elements -> dup_map[row] = ft_strdup(game_elements -> map[row]);
		row++;
	}
	game_elements -> dup_map[row] = NULL;
}

void	flood_fill(t_gelements *game_elements, int player_x, int player_y, \
	int *collectables)
{
	if (player_x > game_elements -> map_height \
	|| player_y > game_elements -> map_width \
	|| player_x < 0 || player_y > 0)
		return ;
	if (game_elements -> dup_map[player_x][player_y] == '1' \
	|| game_elements -> dup_map [player_x][player_y] == 'V')
		return ;
	if (game_elements -> dup_map [player_x][player_y] == 'E' \
	|| game_elements -> dup_map [player_x][player_y] == 'V')
		game_elements -> exit = 0;
	if (game_elements -> dup_map [player_x][player_y] == 'C' \
	|| game_elements -> dup_map [player_x][player_y] == 'V')
		*collectables -= 1;
	game_elements -> dup_map [player_x][player_y] = 'V';
	flood_fill(game_elements, player_x + 1, player_y, collectables);
	flood_fill(game_elements, player_x - 1, player_y, collectables);
	flood_fill(game_elements, player_x, player_y + 1, collectables);
	flood_fill(game_elements, player_x, player_y - 1, collectables);
}

void	flood_fill_caller(t_gelements *game_elements)
{
	int	collectables;

	collectables = game_elements -> collectable;
	flood_fill(game_elements, game_elements -> player_x, \
	game_elements -> player_y, &collectables);
	if (game_elements -> exit != 0 || collectables != 0)
	{
		free_2d(game_elements -> map);
		free_2d(game_elements -> dup_map);
		error_escaper("Error\nExit or collectables unreachable\n");
	}
}

void	map_edges_checker(t_gelements *game_elements)
{
	int	row;
	int	col;
	int	line_len;
	int	frst_iter;

	row = 0;
	col = 0;
	line_len = ft_strlen(game_elements -> map[row]) - 1;
	frst_iter = 1;
	while (game_elements -> map[row])
	{
		while (game_elements -> map[row][col])
		{
			if (((row == 0 || col == 0) && frst_iter != 1) ||game_elements -> map[0][col] != '1' \
			|| game_elements -> map[row][0] != '1'\
			|| game_elements -> map[row][line_len] != '1' \
			|| game_elements -> map[game_elements -> map_height][col] != '1')
				map_freeing(game_elements, "Error\nMap is not closed!\n");
			col++;
			frst_iter = 0;
		}
		row++;
	}
}
