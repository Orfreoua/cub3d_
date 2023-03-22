/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:13:41 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 18:23:03 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	init_ray(t_data *data)
{
	data->args.player.hit1 = data->args.player.pos;
	data->args.player.hit2 = data->args.player.pos;
	data->args.player.f_hit = data->args.player.pos;
}

double	update_angle(double angle, double move)
{
	angle = angle + move;
	if (angle <= 0)
		angle = 360 + angle;
	if (angle >= 360)
		angle = angle - 360;
	return (angle);
}

int	determine_direction_from_angle(double angle)
{
	if (angle == 0 || angle == 360)
		return (1);
	else if (angle == 90)
		return (2);
	else if (angle == 180)
		return (3);
	else if (angle == 270)
		return (4);
	else if (angle > 0 && angle < 90)
		return (5);
	else if (angle > 90 && angle < 180)
		return (6);
	else if (angle > 180 && angle < 270)
		return (7);
	else if (angle > 270 && angle < 360)
		return (8);
	return (-1);
}

double	calculate_distance_to_wall(t_data *data, double angle)
{
	int		direction;
	double	hypo;
	t_point	decimal;

	decimal.x = data->args.player.pos.x - (int)data->args.player.pos.x;
	decimal.y = data->args.player.pos.y - (int)data->args.player.pos.y;
	direction = determine_direction_from_angle(angle / (M_PI / 180));
	init_ray(data);
	if (direction == 1)
		hypo = detect_wall_distance_east(data);
	else if (direction == 2)
		hypo = detect_wall_distance_south(data);
	else if (direction == 3)
		hypo = detect_wall_distance_west(data);
	else if (direction == 4)
		hypo = detect_wall_distance_north(data);
	else if (direction == 5)
		hypo = ft_se(data, decimal, angle);
	else if (direction == 6)
		hypo = ft_sw(data, decimal, angle);
	else if (direction == 7)
		hypo = ft_nw(data, decimal, angle);
	else if (direction == 8)
		hypo = ft_ne(data, decimal, angle);
	else
		hypo = 0.0; //error.
	return (hypo);
}
char	ft_check_hit(t_data *data, char hit, double x, double y)
{
	if (hit == 'e')
		return (data->args.map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 's')
		return (data->args.map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 'w')
		return (data->args.map.grid[(unsigned int)y][(unsigned int)(x - 1)]);
	else if (hit == 'n')
		return (data->args.map.grid[(unsigned int)(y - 1)][(unsigned int)x]);
	return ('1');
}

