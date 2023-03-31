/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:21:14 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:38:01 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	big_len_y(int **map)
{
	int	y;
	int	x;
	int	big;

	y = 0;
	big = 0;
	while (map[y][0] != -1)
	{
		x = 0;
		while (map[y][x] != -1)
			x++;
		if (big < x)
			big = x;
		y++;
	}
	return (big);
}

void	map_moins_un(t_file *file, int y, int x)
{
	file->tab[y] = (int *)malloc(sizeof(int) * (file->len_y + 1));
	if (!file->tab[y] && file->parsing_map_msg == NULL)
	{
		file->parsing_map_msg = MALLOC_FAILED;
		free_tab(file->tab, y);
		return ;
	}
	x = 0;
	while (file->map[y][x] != -1)
	{
		file->tab[y][x] = file->map[y][x];
		x++;
	}
	while (x < file->len_y)
	{
		file->tab[y][x] = 2;
		x++;
	}
	file->tab[y][x] = -1;
}

void	cpy_next(t_file *file, int y, char *msg)
{
	file->parsing_map_msg = msg;
	free_tab(file->tab, y);
	return ;
}

void	cpy_map_tab(t_file *file)
{
	int	y;
	int	x;
	int	leny;

	y = 0;
	x = 0;
	file->len_y = big_len_y(file->map);
	leny = len_y(file->map);
	free_tab(file->tab, 0);
	file->tab = (int **)malloc(sizeof(int *) * (leny + 1));
	if (!file->tab)
		return (put_err_msg(file, MALLOC_FAILED));
	while (file->map[y][0] != -1)
	{
		map_moins_un(file, y, x);
		y++;
	}
	file->tab[y] = (int *)malloc(sizeof(int) * (1));
	if (!file->tab[y] && file->parsing_map_msg == NULL)
		cpy_next(file, y, MALLOC_FAILED);
	file->tab[y][0] = -1;
	return ;
}
