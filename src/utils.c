/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:23:04 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/01 06:11:55 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	free_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx.id, game->assets.tile);
	mlx_destroy_image(game->mlx.id, game->assets.wall);
	mlx_destroy_image(game->mlx.id, game->assets.coll);
	mlx_destroy_image(game->mlx.id, game->assets.exit);
	mlx_destroy_image(game->mlx.id, game->assets.p_right);
	mlx_destroy_image(game->mlx.id, game->assets.p_left);
}

void	free_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx.id, game->mlx.win);
	mlx_destroy_display(game->mlx.id);
	if (game->mlx.id)
		free(game->mlx.id);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != 0 && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
