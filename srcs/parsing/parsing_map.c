/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:35:20 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 18:41:04 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

void	check_missing_pos(t_data *data)
{
	if (data->file.textures.north == NULL)
		petf(joi(malicious(NO_NORTH), ft_itoa(data->file.gnl + 1)));
	else if (data->file.textures.south == NULL)
		petf(joi(malicious(NO_SOUTH), ft_itoa(data->file.gnl + 1)));
	else if (data->file.textures.west == NULL)
		petf(joi(malicious(NO_WEST), ft_itoa(data->file.gnl + 1)));
	else if (data->file.textures.east == NULL)
		petf(joi(malicious(NO_EAST), ft_itoa(data->file.gnl + 1)));
	else if (data->file.floor.r == -1)
		petf(joi(malicious(NO_FLOOR), ft_itoa(data->file.gnl + 1)));
	else if (data->file.ceiling.r == -1)
		petf(joi(malicious(NO_CEIL), ft_itoa(data->file.gnl + 1)));
	return ;
}

int	is_it_direction(char *line, int x)
{
	while (line[x] == ' ')
		x++;
	if (line[x] == 'F' && line[x + 1] == ' ')
		return (-15);
	else if (line[x] == 'C' && line[x + 1] == ' ')
		return (-16);
	else if (line[x] == 'N' && line[x + 1] == 'O' && line[x + 2] == ' ')
		return (-11);
	else if (line[x] == 'S' && line[x + 1] == 'O' && line[x + 2] == ' ')
		return (-12);
	else if (line[x] == 'W' && line[x + 1] == 'E' && line[x + 2] == ' ')
		return (-13);
	else if (line[x] == 'E' && line[x + 1] == 'A' && line[x + 2] == ' ')
		return (-14);
	else if (is_one_space(line, x) == 1)
		return (-20);
	else
		return (x);
}

char	*cut_spaces(char *str)
{
	int	x;
	int	y;

	x = ft_strlen(str) - 1;
	y = x;
	while (str[y] == ' ')
		y--;
	if (x != y)
		str = cftp(str, 0, y + 1);
	return (str);
}

int	parsing_map(t_data *data, char *file)
{
	char		*line;
	int			ret;
	static char	*str[512];

	line = NULL;
	data->file.fd = open(file, O_RDONLY);
	ret = 1;
	while (ret >= 0 && data->file.fin == 0)
	{
		ret = parsing_map_nxt(data, ret, line, str);
	}
	ret = map_error(data);
	free(str[data->file.fd]);
	str[data->file.fd] = NULL;
	return (ret);
}

int	parsing_map_nxt(t_data *data, int ret, char *line, char **str)
{
	ret = get_next_lineo(data->file.fd, &line, str);
	data->file.gnl++;
	while (ret != 0 && line[0] == '\0')
	{
		free(line);
		data->file.gnl++;
		ret = get_next_lineo(data->file.fd, &line, str);
		data->file.n++;
	}
	if (ret < 0)
		return (pars_error(ret, data));
	else if (ret == 0)
		data->file.fin = 1;
	ret = it_s_ok_to_be_line(data, line);
	if (ret < 0 || data->file.ret == -3)
	{
		free(line);
		return (pars_error(ret, data));
	}
	free(line);
	return (ret);
}
