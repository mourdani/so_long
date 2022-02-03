/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:29:19 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/03 04:14:52 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	game_init(t_game *game, char *argv)
{
	int		i;

	i = 0;
	game->coll_left = 0;
	game->mlx.id = mlx_init();
	if (!game->mlx.id)
		return (1);
	if (map_init(&game->map, argv) == 1)
		return (1);
	if (imgs_init(game->mlx, &game->assets) == 1)
		return (1);
	game->mlx.win = mlx_new_window
		(game->mlx.id, game->map.width * game->assets.width,
			game->map.height * game->assets.height, WIN_NAME);
	if (!game->mlx.win)
		return (1);
	game->moves = 1;
	while (game->map.content[i])
	{
		if (game->map.content[i] == 'C')
			game->coll_left++;
		i++;
	}
	return (0);
}

int	map_content_init(t_map *map, char *argv)
{
	int		fd;
	char	*ret;

	map->content = malloc(sizeof(char) * ((map->width * map->height) + 2));
	fd = open(argv, O_RDONLY);
	if (!fd || !map->content)
		return (1);
	ret = get_next_line(fd);
	if (!ret)
		return (1);
	ft_memcpy(map->content, ret, sizeof(char) * (map->width + 1));
	free(ret);
	ret = get_next_line(fd);
	if (!ret)
		return (1);
	while (ret > 0)
	{
		ft_strlcat(map->content, ret, sizeof(char)
			* (ft_strlen(map->content) + ft_strlen(ret) + 1));
		free(ret);
		ret = get_next_line(fd);
	}
	map->content[ft_strlen(map->content) + 1] = '\0';
	return (0);
}

int	get_player_position(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 'P')
		i++;
	return (i);
}

int	map_init(t_map *map, char *argv)
{
	int		fd;
	char	*ret;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	ret = get_next_line(fd);
	if (!ret)
		return (1);
	map->width = ft_strlen(ret);
	free(ret);
	map->height = 1;
	temp = get_next_line(fd);
	while (temp > 0)
	{
		map->height++;
		free (temp);
		temp = get_next_line(fd);
	}
	if (map_content_init(map, argv) == 1)
		return (1);
	map->position = get_player_position(map->content);
	map->width -= 1;
	return (0);
}

int	imgs_init(t_mlx mlx, t_imgs *img)
{
	img->tile = mlx_xpm_file_to_image
		(mlx.id, PATH_TILE, &img->width, &img->height);
	if (!img->tile)
		return (1);
	img->wall = mlx_xpm_file_to_image
		(mlx.id, PATH_WALL, &img->width, &img->height);
	if (!img->wall)
		return (1);
	img->coll = mlx_xpm_file_to_image
		(mlx.id, PATH_COLL, &img->width, &img->height);
	if (!img->coll)
		return (1);
	img->exit = mlx_xpm_file_to_image
		(mlx.id, PATH_EXIT, &img->width, &img->height);
	if (!img->exit)
		return (1);
	img->p_right = mlx_xpm_file_to_image
		(mlx.id, PATH_P_RIGHT, &img->width, &img->height);
	if (!img->p_right)
		return (1);
	img->p_left = mlx_xpm_file_to_image
		(mlx.id, PATH_P_LEFT, &img->width, &img->height);
	if (!img->p_left)
		return (1);
	return (0);
}
