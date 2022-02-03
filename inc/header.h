/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:20:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/03 03:20:37 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../inc/get_next_line.h"
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>

# define WIN_NAME "so_long"
# define PATH_TILE "assets/tile.xpm"
# define PATH_WALL "assets/wall.xpm"
# define PATH_COLL "assets/collectible.xpm"
# define PATH_P_RIGHT "assets/player_right.xpm"
# define PATH_P_LEFT "assets/player_left.xpm"
# define PATH_EXIT "assets/exit.xpm"

typedef struct coord{
	int		x;
	int		y;
	int		i;
	int		first_elem;
	int		last_elem;
}t_coord;

typedef struct t_imgs{
	void	*tile;
	void	*wall;
	void	*coll;
	void	*p_right;
	void	*p_left;
	void	*exit;
	int		height;
	int		width;
}t_imgs;

typedef struct t_map{
	int		width;
	int		height;
	char	*content;
	int		position;
	int		next_pos;
}t_map;

typedef struct t_mlx{
	void	*id;
	void	*win;
}t_mlx;

typedef struct t_game{
	t_mlx	mlx;
	t_map	map;
	t_imgs	assets;
	int		moves;
	int		coll_left;
}t_game;

/*	init.c 				*/
int		map_init(t_map *map, char *argv);
int		imgs_init(t_mlx mlx, t_imgs *img);
int		game_init(t_game *game, char *argv);
/*	actions.c			*/
int		reduce_win(t_game *game);
int		close_win(t_game *game);
int		print_moves_number(int keycode, t_game *game);
void	get_w_h(int i, int *w, int *h, char *ret);
/*	moves.c			*/
int		moves(int keycode, t_game *game);
void	free_mlx(t_game *game);
void	free_imgs(t_game *game);

/*	print_map.c		*/
void	print_map(t_mlx *mlx, t_map map, t_imgs img);
void	update_map(t_game *game);
/*	utils.c 			*/
void	*ft_memcpy(void *dest, void *src, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
void	ft_swap(char *a, char *b);
/*	errors.c 			*/
int		check_err_foreign_char(char *str);
int		fill_coord(int param, t_coord *co, t_game game);
int		check_err_border(char *ret);
int		check_err_available_char(char *str);
int		check_err_map_file(char *argv);
int		check_err(char *argv);
#endif
