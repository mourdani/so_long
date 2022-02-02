/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:38:27 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/01 06:45:10 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	print_map(t_mlx *mlx, t_map map, t_imgs img)
{
	t_coord	co;

	co.x = 0;
	co.y = 0;
	co.i = -1;
	while (map.content[++co.i])
	{
		if (map.content[co.i] == '\n')
		{
			co.x = 0;
			co.y += img.height;
			co.i++;
		}
		if (map.content[co.i] == '1')
			mlx_put_image_to_window(mlx->id, mlx->win, img.wall, co.x, co.y);
		else if (map.content[co.i] == '0')
			mlx_put_image_to_window(mlx->id, mlx->win, img.tile, co.x, co.y);
		else if (map.content[co.i] == 'C')
			mlx_put_image_to_window(mlx->id, mlx->win, img.coll, co.x, co.y);
		else if (map.content[co.i] == 'P')
			mlx_put_image_to_window(mlx->id, mlx->win, img.p_right, co.x, co.y);
		else if (map.content[co.i] == 'E')
			mlx_put_image_to_window(mlx->id, mlx->win, img.exit, co.x, co.y);
		co.x += img.width;
	}
}

void	update_map(t_game *game)
{
	if (game->map.content[game->map.next_pos] == '1')
		return ;
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
			close_win(game);
			exit(0);
		}
		else
			return ;
	}
	ft_swap(&game->map.content[game->map.position],
		&game->map.content[game->map.next_pos]);
	game->map.position = game->map.next_pos;
	print_map(&game->mlx, game->map, game->assets);
}
