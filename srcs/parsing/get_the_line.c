/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:25:14 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:25:16 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

char	*get_the_line(char *line, int x, t_data *data)
{
	int		y;
	char	*str;

	y = 0;
	while (line[x] == ' ')
		x++;
	x = x + 2;
	while (line[x] == ' ')
	x++;
	while (line[x + y] != '\n' && line[x + y] != '\0')
		y++;
	if (y == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (y + 1));
	if (!str)
		return (NULL);
	y = 0;
	while (line[x] != '\n' && line[x] != '\0')
		str[y++] = line[x++];
	str[y] = '\0';
	data->file.item++;
	return (cut_spaces(str));
}

int	it_s_ok_to_be_line(t_data *data, char *line)
{
	int	x;
	int	ret;

	x = 0;
	ret = is_it_direction(line, x);
	if (ret == -1)
		return (pars_error(ret, data));
	else if (ret == -11 && data->file.textures.north == NULL)
		data->file.textures.north = get_the_line(line, 0, data);
	else if (ret == -12 && data->file.textures.south == NULL)
		data->file.textures.south = get_the_line(line, 0, data);
	else if (ret == -13 && data->file.textures.west == NULL)
		data->file.textures.west = get_the_line(line, 0, data);
	else if (ret == -14 && data->file.textures.east == NULL)
		data->file.textures.east = get_the_line(line, 0, data);
	else if (ret == -15 && data->file.floor.r == -1)
		data->file.ret_flo = get_colors(line, x + 2, &data->file.floor, data);
	else if (ret == -16 && data->file.ceiling.r == -1)
		data->file.ret_cei = get_colors(line, x + 2, &data->file.ceiling, data);
	else if (data->file.item == 6)
		return (create_map(line, data));
	else
		return (pars_error(ret, data));
	return (1);
}
