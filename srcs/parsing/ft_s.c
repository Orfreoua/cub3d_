/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:25:04 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:25:06 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoii(const char *str, int x)
{
	unsigned int	s;

	s = 0;
	if (ft_is_digit(str[x]) == 0)
		return (-1);
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == 45 || str[x] == 43)
		return (-1);
	if (str[x] >= 48 && str[x] <= 57)
	{
		while (str[x] >= 48 && str[x] <= 57)
		{
			s = ((s * 10) + (str[x] - 48));
			x++;
		}
		x++;
	}
	return (s);
}

char	*cftp(char *str, int s, int e)
{
	char	*tmp;
	int		x;

	x = 0;
	if (str == NULL || s == e)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * ((e - s) + 1));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	while (s < e)
		tmp[x++] = str[s++];
	tmp[x] = '\0';
	free(str);
	return (tmp);
}

int	is_one_space(char *line, int x)
{
	while (line[x] != '\0')
	{
		if (line[x] != ' ' && line[x] != '1')
			return (-1);
		x++;
	}
	return (1);
}
