/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:44:14 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/22 19:46:42 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_gelements *game_elements)
{
	if (game_elements -> map[game_elements -> player_y - 1][game_elements -> player_x] == '1')
		return ;
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> game_floor, game_elements -> player_x * PIC_SIZE, game_elements -> player_y * PIC_SIZE);
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> player, game_elements -> player_x * PIC_SIZE, (game_elements -> player_y - 1) * PIC_SIZE);
	game_elements->player_y--;
	if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'C')
	{
		game_elements -> collectable--;
		game_elements -> map[game_elements -> player_y][game_elements -> player_x] = '0';
	}
	// if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'E' && game_elements -> collectable == 0)
	// 	// win_state();
	if (game_elements -> map[game_elements -> player_y + 1][game_elements -> player_x] == 'E')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> exit, game_elements -> player_x * PIC_SIZE, (game_elements -> player_y + 1)* PIC_SIZE);
}

void	down(t_gelements *game_elements)
{
	if (game_elements -> map[game_elements -> player_y + 1][game_elements -> player_x] == '1')
		return ;
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> game_floor, game_elements -> player_x * PIC_SIZE, game_elements -> player_y * PIC_SIZE);
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> player, game_elements -> player_x * PIC_SIZE, (game_elements -> player_y + 1) * PIC_SIZE);
	game_elements->player_y++;
	if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'C')
	{
		game_elements -> collectable--;
		game_elements -> map[game_elements -> player_y][game_elements -> player_x] = '0';
	}
	// if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'E' && game_elements -> collectable == 0)
	// 	// win_state();
	if (game_elements -> map[game_elements -> player_y - 1][game_elements -> player_x] == 'E')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> exit, game_elements -> player_x * PIC_SIZE, (game_elements -> player_y - 1)* PIC_SIZE);
}

void	left(t_gelements *game_elements)
{
	if (game_elements -> map[game_elements -> player_y][game_elements -> player_x - 1] == '1')
		return ;
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> game_floor, game_elements -> player_x * PIC_SIZE, game_elements -> player_y * PIC_SIZE);
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> player, (game_elements -> player_x - 1) * PIC_SIZE, game_elements -> player_y * PIC_SIZE);
	game_elements->player_x--;
		if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'C')
	{
		game_elements -> collectable--;
		game_elements -> map[game_elements -> player_y][game_elements -> player_x] = '0';
	}
	// if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'E' && game_elements -> collectable == 0)
	// 	// win_state();
	if (game_elements -> map[game_elements -> player_y][game_elements -> player_x + 1] == 'E')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> exit, (game_elements -> player_x + 1)* PIC_SIZE, game_elements -> player_y * PIC_SIZE);
}

void	right(t_gelements *game_elements)
{
	if (game_elements -> map[game_elements -> player_y][game_elements -> player_x + 1] == '1')
		return ;
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> game_floor, game_elements -> player_x * PIC_SIZE, game_elements -> player_y * PIC_SIZE);
	mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> player, (game_elements -> player_x + 1)* PIC_SIZE, game_elements -> player_y * PIC_SIZE);
	game_elements->player_x++;
		if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'C')
	{
		game_elements -> collectable--;
		game_elements -> map[game_elements -> player_y][game_elements -> player_x] = '0';
	}
	// if (game_elements -> map[game_elements -> player_y][game_elements -> player_x] == 'E' && game_elements -> collectable == 0)
	// 	// win_state();
	if (game_elements -> map[game_elements -> player_y][game_elements -> player_x - 1] == 'E')
		mlx_put_image_to_window(game_elements -> mlx, game_elements -> win_ptr, game_elements -> game_pics -> exit, (game_elements -> player_x - 1)* PIC_SIZE, game_elements -> player_y * PIC_SIZE);
}
