/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:19:42 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/21 18:19:45 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	put_err_msg(t_file *file, char *msg)
{
	file->parsing_map_msg = msg;
	return ;
}

void	err_in_bis(t_file *file, int y, char *msg)
{
	free_tab(file->tab, y);
	file->parsing_map_msg = msg;
	file->tab = (int **)malloc(sizeof(int *) * (1));
	if (!file->tab)
		return (put_err_msg(file, MALLOC_FAILED));
	file->tab[0] = (int *)malloc(sizeof(int) * (1));
	if (!file->tab[0] && file->parsing_map_msg == NULL)
		return ;
	file->tab[0][0] = -1;
	return ;
}

int	**err_in_add(t_file *file, int y, char *msg)
{
	free_tab(file->tab, y);
	file->parsing_map_msg = msg;
	file->tab = (int **)malloc(sizeof(int *) * (1));
	if (!file->tab)
		return (put_err_msg(file, MALLOC_FAILED), NULL);
	file->tab[0] = (int *)malloc(sizeof(int) * (1));
	if (!file->tab[0] && file->parsing_map_msg == NULL)
		return (err_in_add(file, 0, MALLOC_FAILED));
	file->tab[0][0] = -1;
	return (file->tab);
}

void	cpy_tab_tab_bis(t_file *file)
{
	int	y;
	int	x;
	int	leny;

	y = 0;
	x = 0;
	file->len_y = big_len_y(file->tab);
	leny = len_y(file->tab);
	free_tab(file->taby, file->y);
	file->taby = (int **)malloc(sizeof(int *) * (leny + 1));
	if (!file->taby)
		return (put_err_msg(file, MALLOC_FAILED));
	while (file->tab[y][0] != -1)
	{
		map_moins_un_b(file, y, x);
		y++;
	}
	file->taby[y] = (int *)malloc(sizeof(int) * (1));
	if (!file->taby[y] && file->parsing_map_msg == NULL)
		cpy_next(file, y, MALLOC_FAILED);
	file->taby[y][0] = -1;
	return ;
}
