/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:49:06 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/03 03:59:36 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_err_foreign_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1'
			&& str[i] != '0'
			&& str[i] != 'P'
			&& str[i] != 'E'
			&& str[i] != 'C'
			&& str[i] != '\n'
		)
			return (1);
		i++;
	}
	return (0);
}

int	check_err_available_char(char *str)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			p++;
		if (str[i] == 'E')
			e++;
		i++;
	}
	if (p != 1 || e != 1)
		return (1);
	return (0);
}

int	check_err_border(char *ret)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	get_w_h(i, &w, &h, ret);
	while (ret[i])
	{
		while (i <= w - 1)
		{
			if (ret[i] != '1' || ret[i + ((w + 1) * (h - 1))] != '1')
				return (1);
			i++;
		}
		if (ret[i] == '\n' && ret[i + 1] != '\0'
			&& (ret[i - 1] != '1' || ret[i + 1] != '1'))
			return (1);
		i++;
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
		printf("FILE FORMAT NOT SUPPORTED\n");
		return (1);
	}
	return (0);
}

int	check_err(char *argv)
{
	int		fd;
	char	ret[999999];
	int		n;

	if (check_err_map_file(argv) == 1)
		return (1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("FILE NOT FOUND\n");
		return (1);
	}
	n = read(fd, ret, 999999);
	if (n == -1)
		return (1);
	if (check_err_foreign_char(ret) == 1)
		return (1);
	if (check_err_available_char(ret) == 1)
		return (1);
	if (check_err_border(ret) == 1)
		return (1);
	return (0);
}
