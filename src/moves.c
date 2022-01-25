/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:16:12 by mourdani          #+#    #+#             */
/*   Updated: 2022/01/25 21:23:18 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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
