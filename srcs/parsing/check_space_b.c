/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:05:52 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:05:55 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	check_wall_bis(t_file *file)
{
	cpy_tab_tab_bis(file);
	file->zone++;
	file->two = file->zone;
	for_is_two(file);
	transformers_bis(file);
	find_stack(file);
	file->map_sep = NULL;
	check_taby(file, 0, 0);
}

void	check_space_nxt_b(t_file *file, int y, int x, int **tab)
{
	if (y == 0 || x == 0 || tab[y + 1][0] == -1)
		file->p_map_msg = FLO_MAP;
	else
	{
		if (tab[y - 1][x] == 2)
			file->p_map_msg = FLO_MAP;
		else if (tab[y][x - 1] == 2)
			file->p_map_msg = FLO_MAP;
		else if (tab[y - 1][x - 1] == 2)
			file->p_map_msg = FLO_MAP;
		else if (tab[y - 1][x + 1] == 2)
			file->p_map_msg = FLO_MAP;
	}
}

void	check_space_nxt_bis_b(t_file *file, int y, int x, int **tab)
{
	if (tab[y][x - 1] == 0)
		file->p_map_msg = FLO_MAP;
	else if (y > 0 && tab[y - 1][x] == 0)
		file->p_map_msg = FLO_MAP;
	else if (y > 0 && tab[y - 1][x - 1] == 0)
		file->p_map_msg = FLO_MAP;
	else if (tab[y][x - 1] > 2)
		file->taby[y][x] = file->taby[y][x - 1];
	else if (y > 0 && tab[y - 1][x] == 0)
		file->taby[y][x] = file->taby[y - 1][x];
}
