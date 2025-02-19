/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:03:52 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/19 19:16:42 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# include "ft_printf.h"

# define PIC_SIZE 50

typedef struct s_game_pictures
{
	void	*player;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*game_floor;
}	t_game_pics;

typedef struct s_game_elements
{
	void		*mlx;
	void		*win_ptr;
	int			player;
	int			collectable;
	int			exit;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			map_width;
	int			map_height;
	char		**map;
	char		**dup_map;
	t_game_pics	*game_pics;
}	t_gelements;

void	error_escaper(char *msg);
void	map_parser(char *map, t_gelements *game_elements);
void	map_freeing(t_gelements *game_elements, char *msg);
void	newline_remover(char **map);
void	other_elements_validator(t_gelements *game_elements);
void	map_copier(t_gelements *game_elements);
void	free_2d(char **arr);
void	flood_fill_caller(t_gelements *game_elements);
void	player_location(t_gelements *game_elements);
void	map_edges_checker(t_gelements *game_elements);

#endif
