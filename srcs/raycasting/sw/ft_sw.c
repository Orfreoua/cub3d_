/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:07:58 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 17:28:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	ft_sw(t_data *data, t_point decimal, double angle)
{
	if (decimal.x / cos((M_PI / 2) - (angle - (M_PI / 2)))
		<= (1 - decimal.y) / cos(angle - (M_PI / 2)))
	{
		data->ray.hypo = ft_sw_x(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if ((1 - decimal.y) / cos(angle - (M_PI / 2))
		<= decimal.x / cos((M_PI / 2) - (angle - (M_PI / 2))))
	{
		data->ray.hypo = ft_sw_y(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_sw_1(data, decimal, angle));
}

double	ft_sw_1(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
			data->args.player.f_hit.x = data->args.player.hit1.x;
			data->args.player.f_hit.y = data->args.player.hit1.y;
		if (decimal.x / cos((M_PI / 2) - (angle - (M_PI / 2)))
			<= (1 - decimal.y) / cos(angle - (M_PI / 2)))
					data->args.player.dir = 'w';
		else
				data->args.player.dir = 's';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_sw_2(data, decimal, angle));
	return (0);
}

double	ft_sw_2(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	data->args.player.f_hit.x = data->args.player.hit2.x;
	data->args.player.f_hit.y = data->args.player.hit2.y;
	if (decimal.x / cos((M_PI / 2) - (angle - (M_PI / 2)))
		<= (1 - decimal.y) / cos(angle - (M_PI / 2)))
		data->args.player.dir = 's';
	else
			data->args.player.dir = 'w';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
