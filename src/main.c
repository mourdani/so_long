/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2021/12/02 06:12:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	game_init(t_game *game, char *argv)
{
	int	i;

	i = 0;
	game->coll_left = 0;
	game->mlx.id = mlx_init();
	map_init(&game->map, argv);
	imgs_init(game->mlx, &game->assets);
	game->mlx.win = mlx_new_window(game->mlx.id, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	game->moves = 1;
	while (game->map.content[i])
	{
		if (game->map.content[i] == 'C')
			game->coll_left++;
		i++;
	}

}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game, argv[1]);
	print_map(&game.mlx, game.map, game.assets);
	printf("map:\n%s\nplayer position in map is :%d\n\n\n", game.map.content, game.map.position);

	mlx_key_hook(game.mlx.win, &key_hook, &game);
	mlx_hook(game.mlx.win, DestroyNotify, NoEventMask, close_win, &game);
	mlx_hook(game.mlx.win, 15, 1L << 16, reduce_win, &game);

	mlx_loop(game.mlx.id);
	return (0);
}
