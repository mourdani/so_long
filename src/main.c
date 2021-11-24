/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/24 17:41:05 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include <stdio.h>

int	map_init(t_map *map, char *argv)
{
	int	fd;
	char	*ret;
	int	n;

	fd = open(argv, O_RDONLY);
	map->width = ft_strlen(get_next_line(fd)) - 1;
	
	map->height = 1;
	while (get_next_line(fd))
		map->height++;

	fd = open(argv, O_RDONLY);
	map->content = malloc(sizeof(char) * (map->width * map->height));
	ret = get_next_line(fd);
	ft_memcpy(map->content,  ret, sizeof(char) * (map->width * map->height));
	while ((ret = get_next_line(fd)) > 0)
		ft_strlcat(map->content,  ret, sizeof(char) * (ft_strlen(map->content) + ft_strlen(ret) + 1));
}

int	imgs_init(t_mlx mlx, t_imgs *img)
{
	img->tile = mlx_xpm_file_to_image(mlx.id, PATH_TILE, &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx.id, PATH_WALL, &img->width, &img->height);
	img->coll = mlx_xpm_file_to_image(mlx.id, PATH_COLL, &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(mlx.id, PATH_EXIT, &img->width, &img->height);
	img->p_right = mlx_xpm_file_to_image(mlx.id, PATH_P_RIGHT, &img->width, &img->height);
	img->p_left = mlx_xpm_file_to_image(mlx.id, PATH_P_LEFT, &img->width, &img->height);
}

int	print_map(t_mlx *mlx, t_map map, t_imgs img)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (i < ft_strlen(map.content))
	{
		if (map.content[i] == '\n')
		{
			x = 0;
			y += img.height;
			i++;
		}
		if (map.content[i] == '1')
		    mlx_put_image_to_window(mlx->id, mlx->win, img.wall, x, y);
		else if (map.content[i] == '0')
		    mlx_put_image_to_window(mlx->id, mlx->win, img.tile, x, y);
		else if (map.content[i] == 'C')
		    mlx_put_image_to_window(mlx->id, mlx->win, img.coll, x, y);
		else if (map.content[i] == 'P')
			mlx_put_image_to_window(mlx->id, mlx->win, img.p_right, x, y);
		else if (map.content[i] == 'E')
			mlx_put_image_to_window(mlx->id, mlx->win, img.exit, x, y);
		x += img.width;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_imgs	assets;

	mlx.id = mlx_init();
	map_init(&map, argv[1]);
	imgs_init(mlx, &assets);
	mlx.win = mlx_new_window(mlx.id, map.width * assets.width, map.height * assets.height, WIN_NAME);
	print_map(&mlx, map, assets);

	mlx_loop(mlx.id);
}
