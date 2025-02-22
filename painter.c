/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:54:07 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/22 20:42:12 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_lovely_norm(t_gelements *game_elements, int i, int j)
{
	if (game_elements -> map[i][j] == '1')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, \
		game_elements -> game_pics -> wall, j * PIC_SIZE, i * PIC_SIZE);
	else if (game_elements -> map[i][j] == '0')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, \
		game_elements -> game_pics -> game_floor, j * PIC_SIZE, i * PIC_SIZE);
	else if (game_elements -> map[i][j] == 'P')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, \
		game_elements -> game_pics -> player, j * PIC_SIZE, i * PIC_SIZE);
	else if (game_elements -> map[i][j] == 'C')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, \
		game_elements -> game_pics -> collectable, j * PIC_SIZE, i * PIC_SIZE);
	else if (game_elements -> map[i][j] == 'E')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, \
		game_elements -> game_pics -> exit, j * PIC_SIZE, i * PIC_SIZE);
}

void	render_map(t_gelements *game_elements)
{
	int	i;
	int	j;

	i = 0;
	while (game_elements -> map[i])
	{
		j = 0;
		while (game_elements -> map[i][j])
		{
			the_lovely_norm(game_elements, i, j);
			j++;
		}
		i++;
	}
}
