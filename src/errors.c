/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:49:06 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/01 07:11:09 by mourdani         ###   ########.fr       */
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
		|| argv[i - 4] != '.')
	{
		printf("file format of map: \".ber\"\n");
		return (1);
	}
	return (0);
}

int	fill_coords(int param, t_coord *co, t_game game)
{
	if (param == 1)
	{
		co->x = 0;
		co->y = 0;
		co->i = -1;
		while (co->x < game.map.width)
		{
			if (game.map.content[co->x++] != '1')
				return (1);
		}
	}
	if (param == 2)
	{
		co->first_elem = ++co->x;
		co->last_elem = co->x + game.map.width - 1;
	}
	return (0);
}

int	check_err_border(t_game game)
{
	t_coord		co;

	if (fill_coords(1, &co, game) == 1)
		return (1);
	fill_coords(2, &co, game);
	while (++co.i < game.map.height - 1)
	{
		if (game.map.content[co.first_elem + co.y] != '1'
			|| game.map.content[co.last_elem + co.y] != '1'
			|| game.map.content[co.last_elem + co.y + 1] != '\n' )
			return (1);
		co.y += game.map.width + 1;
	}
	co.y -= game.map.width + 1;
	while (co.first_elem + co.y < co.last_elem + co.y)
	{
		if (game.map.content[co.first_elem++ + co.y] != '1')
			return (1);
	}
	if (game.map.content[co.last_elem + co.y + 1] != '\n')
		return (1);
	return (0);
}
