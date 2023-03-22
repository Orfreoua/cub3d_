/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:55:39 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 16:53:24 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

double	detect_wall_distance_east(t_data *data)
{
	int	i;

	i = 0;
	while (data->args.player.f_hit.x <= data->args.map.size.width && data->args.map.grid
		[(int)data->args.player.f_hit.y][(int)data->args.player.f_hit.x] != '1')
	{
		data->args.player.f_hit.x = (int)data->args.player.pos.x + i;
		data->args.player.f_hit.y = data->args.player.pos.y;
		i++;
	}
	return (data->args.player.f_hit.x - data->args.player.pos.x);
}

double	detect_wall_distance_west(t_data *data)
{
	int	i;

	i = 0;
	while (data->args.player.f_hit.x >= 1 && data->args.map.grid
		[(int)data->args.player.f_hit.y][(int)data->args.player.f_hit.x - 1] != '1')
	{
		data->args.player.f_hit.x = (int)data->args.player.pos.x - i;
		data->args.player.f_hit.y = data->args.player.pos.y;
		i++;
	}
	return (data->args.player.pos.x - data->args.player.f_hit.x);
}

double	detect_wall_distance_south(t_data *data)
{
	int	i;

	i = 0;
	while (data->args.player.f_hit.y <= data->args.map.size.height && data->args.map.grid
		[(int)data->args.player.f_hit.y][(int)data->args.player.f_hit.x] != '1')
	{
		data->args.player.f_hit.x = data->args.player.pos.x;
		data->args.player.f_hit.y = (int)data->args.player.pos.y + i;
		i++;
	}
	return (data->args.player.f_hit.y - data->args.player.pos.y);
}

double	detect_wall_distance_north(t_data *data)
{
	int	i;

	i = 0;
	while (data->args.player.f_hit.y >= 1 && data->args.map.grid
		[(int)data->args.player.f_hit.y - 1][(int)data->args.player.f_hit.x] != '1')
	{
		data->args.player.f_hit.x = data->args.player.pos.x;
		data->args.player.f_hit.y = (int)data->args.player.pos.y - i;
		i++;
	}
	return (data->args.player.pos.y - data->args.player.f_hit.y);
}
