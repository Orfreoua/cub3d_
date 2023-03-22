/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_se_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:07:32 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 17:54:34 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

double	*ft_se_y(t_data *data, t_point decimal, double angle)
{
	int		i;
	double	*hypo;

	i = 0;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	while (data->args.player.hit1.y <= data->args.map.size.height && data->args.player.hit1.x
		<= data->args.map.size.width && ft_check_hit(data, 's',
			data->args.player.hit1.x, data->args.player.hit1.y) != '1')
	{
		hypo[0] = ((1 - decimal.y) + i) / cos(M_PI / 2 - angle);
		data->args.player.hit1.x = (int)data->args.player.pos.x + decimal.x + sqrt(
				hypo[0] * hypo[0] - (((1 - decimal.y) + i) * ((1 - decimal.y) + i)));
		data->args.player.hit1.y = (int)data->args.player.pos.y + i + 1;
		i++;
	}
	hypo[1] = ft_se_y_1(data, decimal, angle);
	return (hypo);
}

double	ft_se_y_1(t_data *data, t_point decimal, double angle)
{
	int		i;
	double	hypo;

	i = 0;
	while (data->args.player.hit2.y <= data->args.map.size.height && data->args.player.hit2.x
		<= data->args.map.size.width && ft_check_hit(data, 'e',
			data->args.player.hit2.x, data->args.player.hit2.y) != '1')
	{
		hypo = ((1 - decimal.x) + i) / cos(angle);
		data->args.player.hit2.x = (int)data->args.player.pos.x + i + 1;
		data->args.player.hit2.y = (int)data->args.player.pos.y + decimal.y + sqrt(
				hypo * hypo - (((1 - decimal.x) + i) * ((1 - decimal.x) + i)));
		i++;
	}
	return (hypo);
}
