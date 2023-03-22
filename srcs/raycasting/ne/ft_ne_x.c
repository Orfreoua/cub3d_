/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ne_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:06:40 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 17:32:03 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	*ft_ne_x(t_data *data, t_point decimal, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = (1 - decimal.x) / cos((2 * M_PI) - angle);
	data->args.player.hit1.x = (int)data->args.player.pos.x + 1;
	data->args.player.hit1.y = (int)data->args.player.pos.y + decimal.y
		- sqrt((hypo[0] * hypo[0]) - ((1 - decimal.x) * (1 - decimal.x)));
	while (data->args.player.hit1.y >= 0 && data->args.player.hit1.x <= data->args.map.size.width
		&& ft_check_hit(data, 'e', data->args.player.hit1.x,
			data->args.player.hit1.y) != '1')
	{
		hypo[0] = ((1 - decimal.x) + i) / cos((2 * M_PI) - angle);
		data->args.player.hit1.x = (int)data->args.player.pos.x + 1 + i;
		data->args.player.hit1.y = (int)data->args.player.pos.y + decimal.y - sqrt((hypo[0]
					* hypo[0]) - (((1 - decimal.x) + i) * ((1 - decimal.x) + i)));
		i++;
	}
	hypo[1] = ft_ne_x_1(data, decimal, angle);
	return (hypo);
}

double	ft_ne_x_1(t_data *data, t_point decimal, double angle)
{	
	int		i;
	double	hypo;

	i = 1;
	hypo = decimal.y / cos((M_PI / 2) - ((2 * M_PI) - angle));
	data->args.player.hit2.x = (int)data->args.player.pos.x + decimal.x + sqrt((hypo * hypo) - (decimal.y * decimal.y));
	data->args.player.hit2.y = (int)data->args.player.pos.y;
	while (data->args.player.hit2.y >= 0 && data->args.player.hit2.x <= data->args.map.size.width
		&& ft_check_hit(data, 'n', data->args.player.hit2.x,
			data->args.player.hit2.y) != '1')
	{
		hypo = (decimal.y + i) / cos((M_PI / 2) - ((2 * M_PI) - angle));
		data->args.player.hit2.x = (int)data->args.player.pos.x + decimal.x + sqrt((hypo
					* hypo) - ((decimal.y + i) * (decimal.y + i)));
		data->args.player.hit2.y = (int)data->args.player.pos.y - i;
		i++;
	}
	return (hypo);
}
