#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct t_map{
	int	width;
	int	height;
	char	*content;
} t_map;

typedef struct t_image{
	void	*id;
	int	height;
	int	width;
} t_image;

typedef struct t_mlx{
	void	*id;
	void	*window;
	t_image	tile;
	t_image	skull;
	t_image	collectible;
	t_image	player;
} t_mlx;

#define PATH_TILE "assets/tileset.xpm"
#define PATH_SKULL "assets/skull.xpm"
#define PATH_SKULL_END "./assets/skull_end.xpm"
#define PATH_COLLECTIBLE "./assets/collectible.xpm"
#define PATH_ALCHIMIST "./assets/alchimist.xpm"

#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include "src/gnl/get_next_line.h"

#endif
