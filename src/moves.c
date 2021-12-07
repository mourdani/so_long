#include "../inc/header.h"

int free_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx.id, game->assets.tile);
	mlx_destroy_image(game->mlx.id, game->assets.wall);
	mlx_destroy_image(game->mlx.id, game->assets.coll);
	mlx_destroy_image(game->mlx.id, game->assets.exit);
	mlx_destroy_image(game->mlx.id, game->assets.p_right);
	mlx_destroy_image(game->mlx.id, game->assets.p_left);
}

int	free_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx.id, game->mlx.win);
	mlx_destroy_display(game->mlx.id);
	if (game->mlx.id)
		free(game->mlx.id);
}

int	move_up(t_game *game)
{
	game->map.next_pos = game->map.position - game->map.width - 1;
	update_map(game);
}

int	move_down(t_game *game)
{
	game->map.next_pos = game->map.position + game->map.width + 1;
	update_map(game);
}


int	move_left(t_game *game)
{
	game->map.next_pos = game->map.position - 1;
	update_map(game);
}

int	move_right(t_game *game)
{
	game->map.next_pos = game->map.position + 1;
	update_map(game);
}

int	moves(int keycode, t_game *game)
{
	if (keycode == XK_w)
		move_up(game);
	else if (keycode == XK_s)
		move_down(game);
	else if (keycode == XK_d)
		move_right(game);
	else if (keycode == XK_a)
		move_left(game);
	else if (keycode == XK_Escape)
		close_win(game);
	print_moves_number(keycode, game);
}
