/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:36 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/23 18:33:43 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_escaper(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	xpm_to_img(t_gelements *game_elements, t_game_pics *pics)
{
	int	a;

	pics -> game_floor = mlx_xpm_file_to_image(game_elements -> mlx, \
	"textures/game_floor.xpm", &a, &a);
	if (!pics -> game_floor)
		win_closer(game_elements, "Error\nXPM to file image failed!");
	pics -> wall = mlx_xpm_file_to_image(game_elements -> mlx, \
	"textures/wall.xpm", &a, &a);
	if (!pics -> wall)
		win_closer(game_elements, "Error\nXPM to file image failed!");
	pics -> player = mlx_xpm_file_to_image(game_elements -> mlx, \
	"textures/player.xpm", &a, &a);
	if (!pics -> player)
		win_closer(game_elements, "Error\nXPM to file image failed!");
	pics -> collectable = mlx_xpm_file_to_image(game_elements -> mlx, \
	"textures/collectable.xpm", &a, &a);
	if (!pics -> collectable)
		win_closer(game_elements, "Error\nXPM to file image failed!");
	pics -> exit = mlx_xpm_file_to_image(game_elements -> mlx, \
	"textures/exit.xpm", &a, &a);
	if (!pics -> exit)
		win_closer(game_elements, "Error\nXPM to file image failed!");
}

void	init_mlx(t_gelements *game_elements, char *title)
{
	game_elements -> mlx = mlx_init();
	if (!game_elements -> mlx)
		win_closer(game_elements, "Error\nMalloc Faliure\n");
	game_elements -> win_ptr = mlx_new_window(game_elements->mlx, \
	game_elements -> map_width * PIC_SIZE, \
	(game_elements -> map_height + 1) * PIC_SIZE, title);
	if (!game_elements -> win_ptr)
		win_closer(game_elements, "Error\nMalloc Faliure\n");
}

int	main(int ac, char **av)
{
	t_gelements	game_elements;

	if (ac != 2)
		error_escaper("Error\nNot enough arguments!\n");
	ft_bzero(&game_elements, sizeof(t_gelements));
	game_elements.game_pics = malloc(sizeof(t_game_pics));
	if (!game_elements.game_pics)
		error_escaper("Error\nMalloc failure!\n");
	ft_bzero(game_elements.game_pics, sizeof(t_game_pics));
	map_parser(av[1], &game_elements);
	init_mlx(&game_elements, av[1]);
	xpm_to_img(&game_elements, game_elements.game_pics);
	render_map(&game_elements);
	keybinds_handling(&game_elements);
	mlx_loop(game_elements.mlx);
	return (0);
}
