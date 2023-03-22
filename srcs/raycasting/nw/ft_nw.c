/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:07:14 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 17:42:48 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	ft_nw(t_data *data, t_point decimal, double angle)
{
	if (decimal.x / cos(angle - M_PI) <= decimal.y / cos((M_PI / 2) - (angle - M_PI)))
	{
		data->ray.hypo = ft_nw_x(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if (decimal.y / cos((M_PI / 2) - (angle - M_PI)) <= decimal.x / cos(angle - M_PI))
	{
		data->ray.hypo = ft_nw_y(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_nw_1(data, decimal, angle));
}

double	ft_nw_1(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
		data->args.player.f_hit.x = data->args.player.hit1.x;
		data->args.player.f_hit.y = data->args.player.hit1.y;
		if (decimal.x / cos(angle - M_PI) <= decimal.y / cos((M_PI / 2) - (angle - M_PI)))
			data->args.player.dir = 'w';
		else
			data->args.player.dir = 'n';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_nw_2(data, decimal, angle));
	return (0);
}

double	ft_nw_2(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	data->args.player.f_hit.x = data->args.player.hit2.x;
	data->args.player.f_hit.y = data->args.player.hit2.y;
	if (decimal.x / cos(angle - M_PI) <= decimal.y / cos((M_PI / 2) - (angle - M_PI)))
		data->args.player.dir = 'n';
	else
		data->args.player.dir = 'w';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
