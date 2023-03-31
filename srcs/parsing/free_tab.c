/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:45:53 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:45:56 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	free_tab(int **tab, int size)
{
	int	y;

	y = 0;
	if (tab && tab[0][0] == -1 && size == 0)
	{
		free(tab[0]);
		free(tab);
		return ;
	}
	while (tab && y < size && tab[y][0] != -1)
	{
		free(tab[y++]);
	}
	free(tab[y]);
	free(tab);
	return ;
}

void	free_tab_bis(int **tab, int size)
{
	int	y;

	y = 0;
	if (tab && tab[0][0] == -1)
	{
		free(tab[0]);
		free(tab);
		return ;
	}
	while (tab && y < size)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	return ;
}
