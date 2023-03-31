/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:30 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 18:40:32 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	free_mapy(t_data *data)
{
	int	y;

	y = 0;
	while (data->file.mapy[y][0] != '\0')
	{
		free(data->file.mapy[y]);
		y++;
	}
	free(data->file.mapy[y]);
	free(data->file.mapy);
}
