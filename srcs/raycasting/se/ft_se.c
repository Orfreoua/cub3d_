/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_se.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:07:39 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/31 19:28:58 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	se(t_data *data, t_point decimal, double angle)
{
	if ((1 - decimal.x) / cos(angle) <= (1 - decimal.y) / cos(M_PI / 2 - angle))
	{
		data->ray.hypo = se_x(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if ((1 - decimal.y) / cos(M_PI / 2 - angle) <= (1 - decimal.x) / cos(angle))
	{
		data->ray.hypo = se_y(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (se_1(data, decimal, angle));
}

double	se_1(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
		data->args.player.f_hit.x = data->args.player.hit1.x;
		data->args.player.f_hit.y = data->args.player.hit1.y;
		if ((1 - decimal.x) / cos(angle) <= (1 - decimal.y) / cos(M_PI / 2 - angle))
			data->args.player.dir = 'e';
		else
			data->args.player.dir = 's';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (se_2(data, decimal, angle));
}

double	se_2(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	data->args.player.f_hit.x = data->args.player.hit2.x;
	data->args.player.f_hit.y = data->args.player.hit2.y;
	if ((1 - decimal.x) / cos(angle) <= (1 - decimal.y) / cos(M_PI / 2 - angle))
		data->args.player.dir = 's';
	else
		data->args.player.dir = 'e';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
