/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:29:19 by mourdani          #+#    #+#             */
/*   Updated: 2022/01/25 21:31:17 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	game_init(t_game *game, char *argv)
{
	int		i;

	i = 0;
	game->coll_left = 0;
	game->mlx.id = mlx_init();
	map_init(&game->map, argv);
	imgs_init(game->mlx, &game->assets);
	game->mlx.win = mlx_new_window
		(game->mlx.id, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	game->moves = 1;
	while (game->map.content[i])
	{
		if (game->map.content[i] == 'C')
			game->coll_left++;
		i++;
	}
}

int	map_init(t_map *map, char *argv)
{
	int		fd;
	char	*ret;
	int		n;

	fd = open(argv, O_RDONLY);
	ret = get_next_line(fd);
	map->width = ft_strlen(ret);
	free(ret);
	map->height = 1;
	while (ret = get_next_line(fd))
	{
		map->height++;
		free(ret);
	}
	map->content = malloc(sizeof(char) * ((map->width * map->height) + 2));
	map->content[(map->width * map->height) + 1] = '\0';
	fd = open(argv, O_RDONLY);
	ret = get_next_line(fd);
	ft_memcpy(map->content, ret, sizeof(char) * (map->width + 1));
	free(ret);
	while ((ret = get_next_line(fd)) > 0)
	{
		ft_strlcat(map->content, ret, sizeof(char)
			* (ft_strlen(map->content) + ft_strlen(ret) + 1));
		free(ret);
	}
	map->content[ft_strlen(map->content) + 1] = '\0';
	n = 0;
	while (map->content[n] != 'P')
		n++;
	map->position = n;
	map->width -= 1;
}

int	imgs_init(t_mlx mlx, t_imgs *img)
{
	img->tile = mlx_xpm_file_to_image
		(mlx.id, PATH_TILE, &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image
		(mlx.id, PATH_WALL, &img->width, &img->height);
	img->coll = mlx_xpm_file_to_image
		(mlx.id, PATH_COLL, &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image
		(mlx.id, PATH_EXIT, &img->width, &img->height);
	img->p_right = mlx_xpm_file_to_image
		(mlx.id, PATH_P_RIGHT, &img->width, &img->height);
	img->p_left = mlx_xpm_file_to_image
		(mlx.id, PATH_P_LEFT, &img->width, &img->height);
}
