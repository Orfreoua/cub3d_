/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:47:46 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:47:49 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	is_one(t_file *file, int y, int x)
{
	if (y == 0)
		is_one_nxt(file, y, x);
	else if (x == 0)
		is_one_nxt_nxt(file, y, x);
	else
	{
		is_one_nxt_nxt_end(file, y, x);
	}
}

void	is_one_nxt(t_file *file, int y, int x)
{
	if (x == 0)
		file->tab[y][x] = file->zone;
	else if (x < file->len_y && file->tab[y][x - 1] <= 2)
	{
		file->zone++;
		file->tab[y][x] = file->zone;
	}
	else if (x < file->len_y && file->tab[y][x - 1] > 2)
		file->tab[y][x] = file->tab[y][x - 1];
}

void	is_one_nxt_nxt(t_file *file, int y, int x)
{
	if (file->tab[y - 1][x] > 2)
		file->tab[y][x] = file->tab[y - 1][x];
	else if (x < file->len_y && file->tab[y - 1][x] <= 2)
	{
		file->zone++;
		file->tab[y][x] = file->zone;
	}
}

void	is_one_nxt_nxt_end(t_file *file, int y, int x)
{
	if (file->tab[y - 1][x] <= 2 && file->tab[y][x - 1] <= 2)
	{
		file->zone++;
		file->tab[y][x] = file->zone;
	}
	else if (file->tab[y - 1][x] > 2 && file->tab[y][x - 1] > 2
		&& file->tab[y - 1][x] > file->tab[y][x - 1])
	{
		file->tab[y][x] = file->tab[y][x - 1];
		transformers(file, file->tab[y - 1][x], file->tab[y][x - 1]);
	}
	else if (file->tab[y - 1][x] > 2 && file->tab[y][x - 1] > 2
	&& file->tab[y - 1][x] < file->tab[y][x - 1])
	{
		file->tab[y][x] = file->tab[y - 1][x];
		transformers(file, file->tab[y][x - 1], file->tab[y - 1][x]);
	}
	else if (file->tab[y - 1][x] > 2)
		file->tab[y][x] = file->tab[y - 1][x];
	else if (file->tab[y][x - 1] > 2)
		file->tab[y][x] = file->tab[y][x - 1];
}
