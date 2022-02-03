/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/03 03:24:22 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_err(argv[1]) == 1)
	{
		printf("Error\n");
		return (1);
	}
	if (game_init(&game, argv[1]) == 1)
		return (1);
	print_map(&game.mlx, game.map, game.assets);
	mlx_key_hook(game.mlx.win, &moves, &game);
	mlx_hook(game.mlx.win, DestroyNotify, NoEventMask, close_win, &game);
	mlx_hook(game.mlx.win, 15, 1L << 16, reduce_win, &game);
	mlx_loop(game.mlx.id);
	close_win(&game);
	return (0);
}
