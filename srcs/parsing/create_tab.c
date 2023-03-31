/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:17 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:49:19 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	**cpy_tab(t_file *file, int **tmp)
{
	int	y;
	int	x;

	y = 0;
	if (file->map == NULL)
		return (tmp);
	while (file->map[y][0] != -1)
	{
		x = 0;
		while (file->map[y][x] != -1)
			x++;
		free(tmp[y]);
		tmp[y] = (int *)malloc(sizeof(int) * (x + 1));
		if (!tmp[file->y])
			return (err_in_add(file, y, MALLOC_FAILED));
		x = -1;
		while (file->map[y][++x] != -1)
			tmp[y][x] = file->map[y][x];
		tmp[y][x] = file->map[y][x];
		y++;
	}
	return (tmp);
}

int	**add_next_line(t_file *file, int **tmp, char *str)
{
	int	**tab;
	int	x;

	tab = cpy_tab(file, tmp);
	free_tab_bis(file->map, file->y);
	free(tab[file->y - 1]);
	tab[file->y - 1] = (int *)malloc(sizeof(int) * (ft_strlen(str) + 1));
	if (!tab[file->y - 1])
		return (err_in_add(file, file->y - 1, MALLOC_FAILED));
	x = 0;
	while (str[x] != '\0' && str_c(file->src, str[x]) != -1)
	{
		tab[file->y - 1][x] = convert(str[x]);
		if (tab[file->y - 1][x] == 3 && file->pos < 2)
		{
			file->rotate = player_pos(str[x], file, x, file->y);
			tab[file->y - 1][x] = 0;
		}
		else if (tab[file->y - 1][x] == -2 ||
		(tab[file->y - 1][x] == 3 && file->pos < 2))
			return (err_in_add(file, file->y - 1, WRONG_CHAR_IN_MAP));
		x++;
	}
	tab[file->y - 1][x] = -1;
	return (tab);
}

void	create_tab(t_file *file, char *str)
{
	int	**tmp;
	int	y;

	tmp = (int **)malloc(sizeof(int *) * (file->y + 2));
	if (!tmp)
		return (put_err_msg(file, MALLOC_FAILED));
	y = 0;
	while (y <= file->y)
	{
		tmp[y] = (int *)malloc(sizeof(int) * (1));
		if (!tmp[y] && file->parsing_map_msg == NULL)
			return (err_in_bis(file, y, MALLOC_FAILED));
		tmp[y][0] = -1;
		y++;
	}
	file->map = add_next_line(file, tmp, str);
}
