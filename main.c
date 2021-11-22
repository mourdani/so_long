/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/22 04:18:43 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	int	fd;
	char	*buff;
	char	*buff1;
	int	ret;
	int	i = 0;
	int	x = 0;
	int	y = 0;

	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd, &buff1);
	map.width = ft_strlen(buff1);
	map.height = 1;
	while ((ret = get_next_line(fd, &buff1)) > 0)
		++map.height;
	fd = open(argv[1], O_RDONLY);
	mlx.id = mlx_init();
	mlx.window = mlx_new_window(mlx.id, map.width * 32, map.height * 32, "so_long"); 
	mlx.tile.id = mlx_xpm_file_to_image(mlx.id, PATH_TILE, &mlx.tile.width, &mlx.tile.height);
	mlx.skull.id = mlx_xpm_file_to_image(mlx.id, PATH_SKULL, &mlx.skull.width, &mlx.skull.height);
	mlx.collectible.id = mlx_xpm_file_to_image(mlx.id, PATH_COLLECTIBLE, &mlx.collectible.width, &mlx.collectible.height);
	mlx.player.id = mlx_xpm_file_to_image(mlx.id, PATH_ALCHIMIST, &mlx.player.width, &mlx.player.height);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		while (buff[i])
		{	
			if (buff[i] == '1')
				mlx_put_image_to_window(mlx.id, mlx.window, mlx.skull.id, x, y);
			if (buff[i] == '0')
				mlx_put_image_to_window(mlx.id, mlx.window, mlx.tile.id, x, y);
			if (buff[i] == 'C')
				mlx_put_image_to_window(mlx.id, mlx.window, mlx.collectible.id, x, y);
			if (buff[i] == 'P')
				mlx_put_image_to_window(mlx.id, mlx.window, mlx.player.id, x, y);
			x += 32;
			i++;
		}
		x = 0;
		i = 0;
		y += 32;
	}
	mlx_loop(mlx.id);
}
