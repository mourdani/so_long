/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/01 01:01:48 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_err(t_game game, char *argv)
{
	if (check_err_foreign_char(game) == 1)
		return (1);
	if (check_err_available_char(game) == 1)
		return (1);
	if (check_err_border(game) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_err_map_file(argv[1]) == 1)
	{
		printf("Error\n");
		return (0);
	}
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
