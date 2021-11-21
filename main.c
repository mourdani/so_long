/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/21 17:21:32 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int fd;

	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);

	mlx.id = mlx_init();
	mlx.window = mlx_new_window(mlx.id, 1200, 300, "so_long"); 
	mlx.tile.id = mlx_xpm_file_to_image(mlx.id, PATH_TILE, &mlx.tile.width, &mlx.tile.height);
	mlx_put_image_to_window(mlx.id, mlx.window, mlx.tile.id, 0, 0);
	mlx_loop(mlx.id);
}
