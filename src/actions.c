/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 03:29:14 by mourdani          #+#    #+#             */
/*   Updated: 2021/12/07 03:29:15 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	close_win(t_game *game)
{
	free_imgs(game);
	free_mlx(game);
	free(game->map.content);
	printf("Window closed\n");
	exit(0);
}

int	reduce_win(t_game *game)
{
	print_map(&game->mlx, game->map, game->assets);
	return (0);
}

int	print_moves_number(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s || keycode == XK_d || keycode == XK_a )
	{
		printf("Number of movements : %d\n", game->moves);
		game->moves++;
	}
  return (0);
}
