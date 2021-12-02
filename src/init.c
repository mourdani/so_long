#include "../inc/header.h"

int	map_init(t_map *map, char *argv)
{
	int	fd;
	char	*ret;
	int	n;

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
	fd = open(argv, O_RDONLY);
	ret = get_next_line(fd);
	ft_memcpy(map->content,  ret, sizeof(char) * (map->width + 1));
	free(ret);
	while ((ret = get_next_line(fd)) > 0)
	{
		ft_strlcat(map->content,  ret, sizeof(char) * (ft_strlen(map->content) + ft_strlen(ret) +1));
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
	img->tile = mlx_xpm_file_to_image(mlx.id, PATH_TILE, &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx.id, PATH_WALL, &img->width, &img->height);
	img->coll = mlx_xpm_file_to_image(mlx.id, PATH_COLL, &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(mlx.id, PATH_EXIT, &img->width, &img->height);
	img->p_right = mlx_xpm_file_to_image(mlx.id, PATH_P_RIGHT, &img->width, &img->height);
	img->p_left = mlx_xpm_file_to_image(mlx.id, PATH_P_LEFT, &img->width, &img->height);
}