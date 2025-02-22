/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:27:52 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/22 18:27:04 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_gelements *game_elements)
{
	// if (XK_Escape == key || XK_q == key)
	// 	win_closer(game_elements);
	if (XK_a == key)
		left(game_elements);
	if (XK_d == key)
		right(game_elements);
	if (key == XK_w)
		up(game_elements);
	if (XK_s == key)
		down(game_elements);
	return (0);
}

void	keybinds_handling(t_gelements *game_elements)
{
	mlx_hook(game_elements -> win_ptr, 2, 1L << 0, key_pressed, game_elements);
	// mlx_hook(game_elements -> win_ptr, 17, 0, win_closer, game_elements);
}
