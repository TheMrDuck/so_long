/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:27:52 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/23 17:45:31 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_gelements *game_elements)
{
	if (!game_elements->mlx || !game_elements->game_pics)
		return ;
	if (game_elements->game_pics->collectable)
		mlx_destroy_image(game_elements->mlx, \
		game_elements->game_pics->collectable);
	if (game_elements->game_pics->player)
		mlx_destroy_image(game_elements->mlx, \
		game_elements->game_pics->player);
	if (game_elements->game_pics->game_floor)
		mlx_destroy_image(game_elements->mlx, \
		game_elements->game_pics->game_floor);
	if (game_elements->game_pics->exit)
		mlx_destroy_image(game_elements->mlx, \
		game_elements->game_pics->exit);
	if (game_elements->game_pics->wall)
		mlx_destroy_image(game_elements->mlx, \
		game_elements->game_pics->wall);
}

int	win_closer(t_gelements *game_elements, char *msg)
{
	destroy_images(game_elements);
	if (game_elements->mlx && game_elements->win_ptr)
		mlx_destroy_window(game_elements->mlx, game_elements->win_ptr);
	if (game_elements->mlx)
	{
		mlx_destroy_display(game_elements->mlx);
		free(game_elements->mlx);
	}
	if (game_elements->game_pics)
		free(game_elements->game_pics);
	if (game_elements->map)
		free_2d(game_elements->map);
	if (game_elements->dup_map)
		free_2d(game_elements->dup_map);
	ft_printf("%s", msg);
	exit(0);
	return (0);
}

int	key_pressed(int key, t_gelements *game_elements)
{
	if (key == XK_Escape || key == XK_q)
		win_closer(game_elements, "");
	if (key == XK_a)
		left(game_elements);
	if (key == XK_d)
		right(game_elements);
	if (key == XK_w)
		up(game_elements);
	if (key == XK_s)
		down(game_elements);
	return (0);
}

void	keybinds_handling(t_gelements *game_elements)
{
	mlx_hook(game_elements -> win_ptr, 2, 1L << 0, key_pressed, game_elements);
	mlx_hook(game_elements -> win_ptr, 17, 0, win_closer, game_elements);
}
