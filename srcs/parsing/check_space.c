/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:41:39 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:41:43 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	check_wall(t_file *file)
{
	int	y;
	int	x;
	int	big;

	y = 0;
	big = 0;
	file->sep = 0;
	while (file->tab[y][0] != -1)
	{
		x = 0;
		while (file->tab[y][x] != -1)
		{
			if (file->tab[y][x] > 2 && big == 0)
				big = file->tab[y][x];
			else if (big != 0 && file->tab[y][x] > big)
				file->sep = 1;
			x++;
		}
		y++;
	}
	file->big = big;
}

void	check_space_nxt(t_file *file, int y, int x)
{
	if (y == 0 || x == 0 || file->tab[y + 1][0] == -1)
		file->p_map_msg = FLO_MAP;
	else
	{
		if (file->tab[y - 1][x] == 2)
			file->p_map_msg = FLO_MAP;
		else if (file->tab[y][x - 1] == 2)
			file->p_map_msg = FLO_MAP;
		else if (file->tab[y - 1][x - 1] == 2)
			file->p_map_msg = FLO_MAP;
		else if (file->tab[y - 1][x + 1] == 2)
			file->p_map_msg = FLO_MAP;
	}
}

void	check_space_nxt_bis(t_file *file, int y, int x)
{
	if (file->tab[y][x - 1] == 0)
		file->p_map_msg = FLO_MAP;
	else if (y > 0 && file->tab[y - 1][x] == 0)
		file->p_map_msg = FLO_MAP;
	else if (y > 0 && file->tab[y - 1][x - 1] == 0)
		file->p_map_msg = FLO_MAP;
}

void	check_space(t_file *file)
{
	int	y;
	int	x;

	y = 0;
	while (file->tab[y][0] != -1 && file->p_map_msg == NULL)
	{
		x = 0;
		while (file->tab[y][x] != -1 && file->p_map_msg == NULL)
		{
			if (file->tab[y][x] == 0)
				check_space_nxt(file, y, x);
			else if (file->tab[y][x] == 2 && x > 0)
				check_space_nxt_bis(file, y, x);
			x++;
		}
		y++;
	}
	return ;
}
