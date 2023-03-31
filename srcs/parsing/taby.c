/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taby.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:02:42 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:03:05 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	check_taby(t_file *file, int x, int y)
{
	while (file->taby[y][0] != -1 && file->map_sep == NULL)
	{
		x = 0;
		while (file->taby[y][x] != -1 && file->map_sep == NULL)
		{
			if (file->taby[y][x] == file->zone)
			{
				if (y == 0 && x == 0)
					taby_y_x(file, x, y);
				else if (y == 0)
					taby_y(file, x, y);
				else if (x == 0)
					taby_x(file, x, y);
				else
					taby_else(file, x, y);
			}
			x++;
		}
		y++;
	}
}

void	taby_y_x(t_file *file, int x, int y)
{
	if (file->taby[y][x] != file->stack
	&& file->taby[y][x] != file->zone)
		file->map_sep = SEP_MAP;
}

void	taby_y(t_file *file, int x, int y)
{
	if (file->taby[y][x - 1] != file->stack
	&& file->taby[y][x - 1] != file->zone)
		file->map_sep = SEP_MAP;
}

void	taby_x(t_file *file, int x, int y)
{
	if (file->taby[y - 1][x] != file->stack
	&& file->taby[y - 1][x] != file->zone)
		file->map_sep = SEP_MAP;
}

void	taby_else(t_file *file, int x, int y)
{
	if (file->taby[y - 1][x] != file->stack
	&& file->taby[y - 1][x] != file->zone)
		file->map_sep = SEP_MAP;
	else if (file->taby[y][x - 1] != file->stack
		&& file->taby[y][x - 1] != file->zone)
		file->map_sep = SEP_MAP;
}
