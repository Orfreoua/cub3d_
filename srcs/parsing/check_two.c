/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:11:16 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:11:20 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	transformers_bis(t_file *file)
{
	int	y;
	int	x;

	y = 0;
	while (file->taby[y][0] != -1)
	{
		x = 0;
		while (file->taby[y][x] != -1)
		{
			if (file->taby[y][x] == 2)
			{
				extra_long_if(file, x, y);
			}
			x++;
		}
		y++;
	}
}

void	extra_long_if(t_file *file, int x, int y)
{
	if (file->taby[y][x - 1] == file->zone
		|| file->taby[y - 1][x] == file->zone
		|| file->taby[y - 1][x - 1] == file->zone
		|| file->taby[y + 1][x] == file->zone
		|| file->taby[y + 1][x + 1] == file->zone
		|| file->taby[y][x + 1] == file->zone)
	{
		file->taby[y][x] = file->zone;
		transformers_bis(file);
	}
}

void	is_two(t_file *file, int y, int x)
{
	if (y == 0 || x == 0 || file->taby[y + 1][0] == -1
		|| file->taby[y][x + 1] == -1)
		file->taby[y][x] = file->zone;
	else if (file->taby[y][x - 1] == file->zone
		|| file->taby[y - 1][x] == file->zone
		|| file->taby[y - 1][x - 1] == file->zone)
		file->taby[y][x] = file->zone;
}
