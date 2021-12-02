#include "../inc/header.h"

int	close_win(void *param)
{
	(void)param;
	exit(0);
}

int	reduce_win(t_game *game)
{
	print_map(&game->mlx, game->map, game->assets);
	printf("window reduced\n");
	return (0);
}

int	print_moves_number(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s || keycode == XK_d || keycode == XK_a )
	{
		printf("Number of movements : %d\n", game->moves);
		game->moves++;
	}
}
int	ft_swap(char *a, char *b)
{
	char	temp;

	temp =0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int	update_map(t_game *game)
{
	if (game->map.content[game->map.next_pos] == '1')
		return (0);
	if (game->map.content[game->map.next_pos] == 'C')
	{
		game->map.content[game->map.next_pos] = '0';
		game->coll_left -= 1;
	}
	if (game->map.content[game->map.next_pos] == 'E')
	{
		if (game->coll_left == 0)
		{
			printf("\n**** YOU WIN ****\n");
			exit(0);
		}
	}
	ft_swap(&game->map.content[game->map.position], &game->map.content[game->map.next_pos]);
	game->map.position = game->map.next_pos;
	print_map(&game->mlx, game->map, game->assets);
	
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

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w)
		move_up(game);
	if (keycode == XK_s)
		move_down(game);
	if (keycode == XK_d)
		move_right(game);
	if (keycode == XK_a)
		move_left(game);
	print_moves_number(keycode, game);
	printf("Collectibles left : %d\n", game->coll_left);
	if (keycode == XK_Escape)
	{
		printf("Window closed\n");
		exit(0);
	}
}
