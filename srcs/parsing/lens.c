/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:13:06 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:13:09 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	len_y(int **map)
{
	int	y;

	y = 0;
	while (map[y][0] != -1)
		y++;
	return (y);
}

int	len_x(int **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] != -1)
		x++;
	return (x);
}
