/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:01:13 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:01:16 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	print_file(t_data *data)
{
	printf("Donnees de la map:\n");
	printf("NO = -%s-\nSO = -%s-\nWE = -%s-\nEA = -%s-\n",
		data->file.textures.north, data->file.textures.south,
		data->file.textures.west, data->file.textures.east);
	printf("F = %d,%d,%d\n", data->file.floor.r, data->file.floor.g,
		data->file.floor.b);
	printf("C = %d,%d,%d\n", data->file.ceiling.r, data->file.ceiling.g,
		data->file.ceiling.b);
	printf("_________________________________________________\n");
}

void	print_tab(int **tab, int stop)
{
	int	y;
	int	x;

	y = 0;
	while (tab && tab[y][0] != stop)
	{
		x = 0;
		while (tab[y][x] != stop)
		{
			if (tab[y][x] == 2)
				printf(".");
			else if (tab[y][x] == 0)
				printf("*");
			else
				printf("%d", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("________________________________________________________\n");
	return ;
}

void	print_map(char **tab)
{
	int	y;
	int	x;

	y = 0;
	while (tab && tab[y][0] != '\0')
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			printf("%c", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("________________________________________________________\n");
	return ;
}
