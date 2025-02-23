/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:44:14 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/23 18:28:29 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_state(t_gelements *gme)
{
	gme -> moves++;
	ft_printf("Moves: %d\n", gme -> moves);
	ft_printf("You WIN!\n");
	win_closer(gme, "NULL");
}

void	up(t_gelements *gme)
{
	if (gme -> map[gme -> player_y - 1][gme -> player_x] == '1')
		return ;
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> game_floor, \
	gme -> player_x * PIC_SIZE, gme -> player_y * PIC_SIZE);
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> player, \
	gme -> player_x * PIC_SIZE, (gme -> player_y - 1) * PIC_SIZE);
	gme->player_y--;
	if (gme -> map[gme -> player_y][gme -> player_x] == 'C')
	{
		gme -> collectable--;
		gme -> map[gme -> player_y][gme -> player_x] = '0';
	}
	if (gme -> map[gme -> player_y][gme -> player_x] == 'E' && \
	gme -> collectable == 0)
		win_state(gme);
	if (gme -> map[gme -> player_y + 1][gme -> player_x] == 'E')
		mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
		gme -> game_pics -> exit, \
		gme -> player_x * PIC_SIZE, (gme -> player_y + 1) * PIC_SIZE);
	gme -> moves++;
	ft_printf("Moves: %d\n", gme -> moves);
}

void	down(t_gelements *gme)
{
	if (gme -> map[gme -> player_y + 1][gme -> player_x] == '1')
		return ;
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> game_floor, \
	gme -> player_x * PIC_SIZE, gme -> player_y * PIC_SIZE);
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> player, \
	gme -> player_x * PIC_SIZE, (gme -> player_y + 1) * PIC_SIZE);
	gme->player_y++;
	if (gme -> map[gme -> player_y][gme -> player_x] == 'C')
	{
		gme -> collectable--;
		gme -> map[gme -> player_y][gme -> player_x] = '0';
	}
	if (gme -> map[gme -> player_y][gme -> player_x] == 'E' && \
	gme -> collectable == 0)
		win_state(gme);
	if (gme -> map[gme -> player_y - 1][gme -> player_x] == 'E')
		mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
		gme -> game_pics -> exit, \
		gme -> player_x * PIC_SIZE, (gme -> player_y - 1) * PIC_SIZE);
	gme -> moves++;
	ft_printf("Moves: %d\n", gme -> moves);
}

void	left(t_gelements *gme)
{
	if (gme -> map[gme -> player_y][gme -> player_x - 1] == '1')
		return ;
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> game_floor, \
	gme -> player_x * PIC_SIZE, gme -> player_y * PIC_SIZE);
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> player, \
	(gme -> player_x - 1) * PIC_SIZE, gme -> player_y * PIC_SIZE);
	gme->player_x--;
	if (gme -> map[gme -> player_y][gme -> player_x] == 'C')
	{
		gme -> collectable--;
		gme -> map[gme -> player_y][gme -> player_x] = '0';
	}
	if (gme -> map[gme -> player_y][gme -> player_x] == 'E' && \
	gme -> collectable == 0)
		win_state(gme);
	if (gme -> map[gme -> player_y][gme -> player_x + 1] == 'E')
		mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
		gme -> game_pics -> exit, \
		(gme -> player_x + 1) * PIC_SIZE, gme -> player_y * PIC_SIZE);
	gme -> moves++;
	ft_printf("Moves: %d\n", gme -> moves);
}

void	right(t_gelements *gme)
{
	if (gme -> map[gme -> player_y][gme -> player_x + 1] == '1')
		return ;
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> game_floor, \
	gme -> player_x * PIC_SIZE, gme -> player_y * PIC_SIZE);
	mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
	gme -> game_pics -> player, \
	(gme -> player_x + 1) * PIC_SIZE, gme -> player_y * PIC_SIZE);
	gme->player_x++;
	if (gme -> map[gme -> player_y][gme -> player_x] == 'C')
	{
		gme -> collectable--;
		gme -> map[gme -> player_y][gme -> player_x] = '0';
	}
	if (gme -> map[gme -> player_y][gme -> player_x] == 'E' && \
	gme -> collectable == 0)
		win_state(gme);
	if (gme -> map[gme -> player_y][gme -> player_x - 1] == 'E')
		mlx_put_image_to_window(gme -> mlx, gme -> win_ptr, \
		gme -> game_pics -> exit, \
		(gme -> player_x - 1) * PIC_SIZE, gme -> player_y * PIC_SIZE);
	gme -> moves++;
	ft_printf("Moves: %d\n", gme -> moves);
}
