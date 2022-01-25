/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2022/01/25 21:49:24 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game, argv[1]);
	if (check_err(game, argv[1]) == 1)
	{
		printf("Error\n");
		return (0);
	}
	print_map(&game.mlx, game.map, game.assets);
	mlx_key_hook(game.mlx.win, &moves, &game);
	mlx_hook(game.mlx.win, DestroyNotify, NoEventMask, close_win, &game);
	mlx_hook(game.mlx.win, 15, 1L << 16, reduce_win, &game);
	mlx_loop(game.mlx.id);
	close_win(&game);
	return (0);
}
