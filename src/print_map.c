#include "../inc/header.h"

int	print_map(t_mlx *mlx, t_map map, t_imgs img)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (map.content[i])
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
