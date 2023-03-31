/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:03:34 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:03:37 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	convert(char c)
{
	if (c == '1' || c == '0')
		return (c - 48);
	else if (c == ' ')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (3);
	return (-2);
}

double	player_pos(char c, t_file *file, int x, int y)
{
	file->pos = 1;
	file->pos_player.x = x + 0.0;
	file->pos_player.y = y + 0.0;
	if (c == 'N')
		return ((2 * M_PI) / 4);
	else if (c == 'S')
		return ((3 * M_PI) / 4);
	else if (c == 'E')
		return (0);
	return ((4 * M_PI) / 4);
}
