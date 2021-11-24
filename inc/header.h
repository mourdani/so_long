#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../src/gnl/get_next_line.h"

#define WIN_NAME "so_long"
#define PATH_TILE "assets/tile.xpm"
#define PATH_WALL "assets/wall.xpm"
#define PATH_COLL "./assets/collectible.xpm"
#define PATH_P_RIGHT "./assets/player_right.xpm"
#define PATH_P_LEFT "./assets/player_left.xpm"
#define PATH_EXIT "./assets/exit.xpm"

typedef struct t_imgs{
	void	*tile;
	void	*wall;
	void	*coll;
	void	*p_right;
	void	*p_left;
	void	*exit;
	int	height;
	int	width;
}t_imgs;

typedef struct t_map{
	int	width;
	int	height;
	char	*content;
}t_map;

typedef struct t_mlx{
	void	*id;
	void	*win;
}t_mlx;

/*	utiles	*/
void	*ft_bzero(void *b, unsigned int n);
void	*ft_memcpy(void *dest, void *src, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

#endif
