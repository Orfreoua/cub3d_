/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:47:08 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/21 21:36:46 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <string.h>

void	not_real_data(t_data *data)
{
	data->args.map.grid = malloc(sizeof(char *) * 6);
	data->args.map.grid[0] = strdup("1111111111");
	data->args.map.grid[1] = strdup("1000110001");
	data->args.map.grid[2] = strdup("1000000001");
	data->args.map.grid[3] = strdup("1000000001");
	data->args.map.grid[4] = strdup("1111111111");
	data->args.map.grid[5] = 0;
	data->args.map.size.height = 5;
	data->args.map.size.width = 10;
	data->args.player.dir = 0;
	data->args.player.pos.x = 3;
	data->args.player.pos.y = 3;
	data->args.player.angle = 0;
	data->args.south.path = strdup("assets/textures/a.xpm");
	data->args.east.path = strdup("assets/textures/b.xpm");
	data->args.north.path = strdup("assets/textures/c.xpm");
	data->args.west.path = strdup("assets/textures/d.xpm");
}
