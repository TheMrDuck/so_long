/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:42 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/18 16:15:17 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	map_filler(char *map, t_gelements *game_elements)
{
	int		file_fd;
	int		i;
	size_t	total_len;
	char	*line;

	i = 0;
	total_len = 0;
	file_fd = open(map, O_RDONLY);
	if (file_fd == -1)
		error_escaper("Error\n Can't open the file!\n");
	game_elements = malloc(sizeof(char *));
	line = get_next_line(file_fd);
	while (line)
	{
		game_elements->map[i] = line;
		line = get_next_line(file_fd);
		i++;
		relocater(game_elements->map, sizeof(game_elements->map) + sizeof(char *), sizeof(game_elements->map));
	}
	for (int i = 0; game_elements->map[i]; i++)
		printf("%s\n", game_elements->map[i]);
}

void	map_parser(char *map, t_gelements *game_elements)
{
	map_filler(map, game_elements);
}
