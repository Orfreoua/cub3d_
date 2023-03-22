/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:06:53 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 17:53:31 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	ft_ne(t_data *data, t_point decimal, double angle)
{
	if ((1 - decimal.x) / cos((2 * M_PI) - angle) <= decimal.y
		/ cos((M_PI / 2) - ((2 * M_PI) - angle)))
	{
		data->ray.hypo = ft_ne_x(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if (decimal.y / cos((M_PI / 2) - ((2 * M_PI) - angle))
		<= (1 - decimal.x) / cos((2 * M_PI) - angle))
	{
		data->ray.hypo = ft_ne_y(data, decimal, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_ne_1(data, decimal, angle));
}

double	ft_ne_1(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
		data->args.player.f_hit.x = data->args.player.hit1.x;
		data->args.player.f_hit.y = data->args.player.hit1.y;
		if ((1 - decimal.x) / cos((2 * M_PI) - angle) <= decimal.y
			/ cos((M_PI / 2) - ((2 * M_PI) - angle)))
			data->args.player.dir = 'e';
		else
			data->args.player.dir = 'n';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_ne_2(data, decimal, angle));
	return (0);
}

double	ft_ne_2(t_data *data, t_point decimal, double angle)
{
	double	hypo;

	data->args.player.f_hit.x = data->args.player.hit2.x;
	data->args.player.f_hit.y = data->args.player.hit2.y;
	if ((1 - decimal.x) / cos((2 * M_PI) - angle)
		<= decimal.y / cos((M_PI / 2) - ((2 * M_PI) - angle)))
		data->args.player.dir = 'n';
	else
		data->args.player.dir = 'e';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
