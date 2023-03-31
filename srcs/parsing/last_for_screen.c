/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_for_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:46:17 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 15:46:23 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

char	**last_for_screen(t_data *data, int y, int x)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * s_y_tab(data->file.map, -1));
	if (!map)
		return (NULL);
	while (data->file.map[y][0] != -1)
	{
		x = -1;
		map[y] = (char *)malloc(sizeof(char) * s_x_tab(data->file.map, -1, y));
		if (!map)
			return (NULL);
		while (data->file.map[y][++x] != -1)
			map[y][x] = data->file.map[y][x] + 48;
		map[y][x] = '\0';
		y++;
	}
	map[y] = (char *)malloc(sizeof(char) * s_x_tab(data->file.map, -1, y));
	if (!map)
		return (NULL);
	map[y][0] = '\0';
	free_tabs(data);
	return (map);
}

int	s_y_tab(int **tab, int stop)
{
	int	y;

	y = 0;
	while (tab && tab[y][0] != stop)
		y++;
	return (y + 1);
}

int	s_x_tab(int **tab, int stop, int y)
{
	int	x;

	x = 0;
	while (tab && tab[y][x] != stop)
		x++;
	return (x + 1);
}
