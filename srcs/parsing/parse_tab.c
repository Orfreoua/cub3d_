/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:44:20 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:45:09 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	transformers(t_file *file, int zone, int new)
{
	int	y;
	int	x;

	y = 0;
	while (file->tab[y][0] != -1)
	{
		x = 0;
		while (file->tab[y][x] != -1)
		{
			if (file->tab[y][x] == zone)
				file->tab[y][x] = new;
			x++;
		}
		y++;
	}
}

void	parse_tab(t_file *file)
{
	int	y;
	int	x;

	y = 0;
	while (file->tab[y][0] != -1 && file->p_map_msg == NULL)
	{
		x = 0;
		while (file->tab[y][x] != -1 && file->p_map_msg == NULL)
		{
			if (file->tab[y][x] == 1)
				is_one(file, y, x);
			x++;
		}
		y++;
	}
	check_wall(file);
	check_space(file);
	check_wall_bis(file);
	if (file->sep == 1 && file->map_sep != NULL)
		file->p_map_msg = file->map_sep;
}
