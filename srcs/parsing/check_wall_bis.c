/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:07:16 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:07:18 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	for_is_two(t_file *file)
{
	int	x;
	int	y;

	y = 0;
	while (file->taby[y][0] != -1)
	{
		x = 0;
		while (file->taby[y][x] != -1)
		{
			if (file->taby[y][x] == 2)
				is_two(file, y, x);
			x++;
		}
		y++;
	}
}

void	find_stack(t_file *file)
{
	int	y;
	int	x;
	int	stack;

	y = 0;
	stack = -1;
	while (file->taby[y][0] != -1)
	{
		x = 0;
		while (file->taby[y][x] != -1)
		{
			if (file->taby[y][x] > 2 && stack == -1)
				stack = file->taby[y][x];
			else if (file->taby[y][x] > 2 && file->taby[y][x] < stack)
				stack = file->taby[y][x];
			x++;
		}
		y++;
	}
	file->stack = stack;
}

int	verif(int **tab, int y, int x, t_file *file)
{
	y = 0;
	while (tab[y][0] != -1 && file->p_map_msg == NULL)
	{
		x = 0;
		while (tab[y][x] != -1 && file->p_map_msg == NULL)
		{
			if (tab[y][x] == 0)
				check_space_nxt_b(file, y, x, tab);
			else if (tab[y][x] == 2 && x > 0)
				check_space_nxt_bis_b(file, y, x, tab);
			x++;
		}
		y++;
	}
	return (0);
}

void	new_small_stack(t_file *file)
{
	int	y;
	int	x;

	y = 0;
	file->zone++;
	cpy_tab_tab_bis(file);
	print_tab(file->taby, -1);
	printf("fin === \n");
	while (file->taby[y][0] != -1)
	{
		x = 0;
		while (file->taby[y][x] != -1)
		{
			if (file->taby[y][x] > 2)
				verif(file->taby, y, x, file);
			x++;
		}
		y++;
	}
}

void	map_moins_un_b(t_file *file, int y, int x)
{
	file->taby[y] = (int *)malloc(sizeof(int) * (file->len_y + 1));
	if (!file->taby[y] && file->parsing_map_msg == NULL)
	{
		file->parsing_map_msg = MALLOC_FAILED;
		free_tab(file->taby, y);
		return ;
	}
	x = 0;
	while (file->tab[y][x] != -1)
	{
		file->taby[y][x] = file->tab[y][x];
		x++;
	}
	while (x < file->len_y)
	{
		file->taby[y][x] = 2;
		x++;
	}
	file->taby[y][x] = -1;
}
