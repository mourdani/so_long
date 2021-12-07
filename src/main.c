/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:11 by mourdani          #+#    #+#             */
/*   Updated: 2021/12/07 03:42:09 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_err_foreign_char(t_game game)
{
	int	i;

	i = 0;
	while (game.map.content[i])
	{
		if (game.map.content[i] != '1'
		&& game.map.content[i] != '0'
		&& game.map.content[i] != 'P'
		&& game.map.content[i] != 'E'
		&& game.map.content[i] != 'C'
		&& game.map.content[i] != '\n'
		)
		{
			printf("character unknown : %c\n", game.map.content[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_err_available_char(t_game game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (game.map.content[i])
	{
		if (game.map.content[i] == 'P')
			p++;
		if (game.map.content[i] == 'E')
			e++;
		i++;
	}
	if (p != 1 || e != 1)
	{
		printf("too many PLAYERs or EXITs\n");
		return (1);
	}
	return (0);
}

int	check_err_map_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] != 'r'
		|| argv[i - 2] != 'e'
		|| argv[i - 3] != 'b'
		|| argv[i - 4] != '.'
		)
	{
		printf("file format of map: \".ber\"\n");
		return (1);
	}
	return (0);

}

int	check_err(t_game game, char *argv)
{
	int i;
	int j;
	int s;
	int first_elem;
	int last_elem;

	i = 0;
	j = 0;
	s = 0;
	if (check_err_map_file(argv) == 1)
		return (1);
	if (check_err_foreign_char(game) == 1)
		return (1);
	if (check_err_available_char(game) == 1)
		return (1);
	printf("map :\n%s\n", game.map.content);
	while (i < game.map.width)
	{
		if (game.map.content[i++] != '1')
			return (1);
	}
	i++;
	first_elem = i;
	last_elem = i + game.map.width - 1;
	while (s < game.map.height - 1)
	{
		if (game.map.content[first_elem + j] != '1'
		|| game.map.content[last_elem + j] != '1'|| game.map.content[last_elem + j + 1] != '\n' )
			return (1);
		j += game.map.width + 1;
		s++;
	}
	j -= game.map.width + 1;
	while (first_elem + j < last_elem + j)
	{
		if (game.map.content[first_elem++ + j] != '1')
			return (1);
	}
	if (game.map.content[last_elem + j + 1] != '\n')
		return (1);

	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game, argv[1]);
	if (check_err(game, argv[1]) == 1)
	{
		printf("Error\n");
		return(0);
	}
	print_map(&game.mlx, game.map, game.assets);

	mlx_key_hook(game.mlx.win, &moves, &game);
	mlx_hook(game.mlx.win, DestroyNotify, NoEventMask, close_win, &game);
	mlx_hook(game.mlx.win, 15, 1L << 16, reduce_win, &game);
	mlx_loop(game.mlx.id);
	close_win(&game);
	return (0);
}
