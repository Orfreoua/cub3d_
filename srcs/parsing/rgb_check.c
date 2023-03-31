/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:59:53 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:59:56 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	get_rgb_r(char *line, int x, t_color *color)
{
	color->r = ft_atoii(line, x);
	while (ft_is_digit(line[x]) == 1)
		x++;
	if (line[x] == ',' && color->r != -1)
		return (x + 1);
	return (-1);
}

int	get_rgb_g(char *line, int x, t_color *color)
{
	if (x < 0)
		return (x);
	color->g = ft_atoii(line, x);
	while (ft_is_digit(line[x]) == 1)
		x++;
	if (line[x] == ',' && color->g != -1)
		return (x + 1);
	return (-2);
}

int	get_rgb_b(char *line, int x, t_color *color)
{
	if (x < 0)
		return (x);
	color->b = ft_atoii(line, x);
	while (ft_is_digit(line[x]) == 1)
		x++;
	if (line[x] == '\0' && color->b != -3)
		return (x);
	return (-3);
}

int	shake_colors(t_color *color, t_data *data)
{
	if ((color->r < 0 || color->r > 255) || (color->g < 0
			|| color->g > 255) || (color->b < 0 || color->b > 255))
		return (-1);
	else if (data->file.ret_flo == -1 || data->file.ret_cei == -1)
		return (-1);
	return (0);
}
