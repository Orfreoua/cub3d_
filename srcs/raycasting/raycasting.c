/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:53:17 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 16:47:31 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	calculate_wall_height(t_data *data, double angle, double tmp)// a voir pour enlever tmp
{
	data->ray.dist = calculate_distance_to_wall(data, tmp);
	data->ray.wall_height = (int)nearbyint((1 / data->ray.dist) * R_HEIGHT);
	data->ray.wall_height = (int)nearbyint(data->ray.wall_height
			* (1 / cos((M_PI / 180) * (data->args.player.angle - angle))));
	data->ray.floored_wall_height = data->ray.wall_height;
}

void	render_scene(t_data *data, t_screen *buff)
{
	int		i;
	double	angle;
	double	tmp;

	i = 0;
	angle = update_angle(data->args.player.angle, -30);
	while (i < R_WIDTH)
	{
		tmp = (M_PI / 180) * angle;
		calculate_wall_height(data, angle, tmp);
		if (data->ray.wall_height > R_HEIGHT)
			data->ray.floored_wall_height = R_HEIGHT;
		//ft_draw_col_c(buff, i, (R_HEIGHT - data->ray.wall_height) / 2,
		//	data->arg.f.color);
		//ft_draw_col_f(buff, i, R_HEIGHT / 2, data->arg.c.color);
		draw_textured_column(data, buff, i, (R_HEIGHT - data->ray.floored_wall_height) / 2);
		angle = update_angle(angle, 0.06);
		i++;
	}
}

