/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:42 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/22 19:43:37 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_extension_handler(char *map)
{
	char	*tmp;
	int		len;

	len = ft_strlen(map);
	tmp = map + len - 4;
	if (ft_strncmp(tmp, ".ber", 4))
		error_escaper("Error\nMap name doesn't end .ber\n");
}

size_t	map_len(char *map)
{
	size_t	i;
	char	*line;
	int		file;

	file = open(map, O_RDONLY);
	if (file == -1)
		error_escaper("Error\nCan't open file!\n");
	i = 0;
	line = get_next_line(file);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		i++;
	}
	close(file);
	return (i);
}

void	map_filler(char *map, t_gelements *game_elements)
{
	int		file_fd;
	int		i;
	size_t	total_len;

	i = 0;
	total_len = map_len(map);
	file_fd = open(map, O_RDONLY);
	if (file_fd == -1)
		error_escaper("Error\n Can't open the file!\n");
	game_elements -> map = malloc(sizeof(char *) * (total_len + 1));
	game_elements -> map[i] = get_next_line(file_fd);
	while (game_elements -> map[i] != 0)
	{
		i++;
		game_elements -> map[i] = get_next_line(file_fd);
	}
	game_elements->map[i] = NULL;
	close(file_fd);
}

void	map_validator(char **map, t_gelements *game_elements)
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
			if (map[i][j] != '1' && map[i][j] != '0' \
			&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				map_freeing(game_elements, "Error\nInvalid Character\n");
			j++;
		}
		if ((ft_strlen(map[i]) != ft_strlen(map[i + 1])))
		{
			if (ft_strlen(map[i + 1]) == 0)
				break ;
			map_freeing(game_elements, "Error\n map not rectangular\n");
		}
		i++;
	}
	game_elements -> map_height = i;
	game_elements -> map_width = j;
}

void	map_parser(char *map, t_gelements *game_elements)
{
	file_extension_handler(map);
	map_filler(map, game_elements);
	newline_remover(game_elements->map);
	map_validator(game_elements -> map, game_elements);
	other_elements_validator(game_elements);
	map_copier(game_elements);
	player_location(game_elements);
	map_edges_checker(game_elements);
	flood_fill_caller(game_elements);
	game_elements->moves = 0;
}
