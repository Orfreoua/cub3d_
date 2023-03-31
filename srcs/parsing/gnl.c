/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:38:46 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:39:20 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/cub3d.h"

int	ft_check(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\n' && str[n] != '\0')
		n++;
	if (str[n] == '\n')
		return ((n + 1) * -1);
	return (n);
}

char	*ft_read_suite(int fd, int n, char *strr, int *rid)
{
	char	buf[BUFFER_SIZE + 1];
	char	*stock;
	int		x;
	int		y;

	*rid = read(fd, buf, BUFFER_SIZE);
	if (*rid < 0)
		return (NULL);
	buf[*rid] = '\0';
	stock = (char *)malloc(sizeof(char) * (n + BUFFER_SIZE + 1));
	if (!stock)
		return (NULL);
	x = 0;
	while (x < n + BUFFER_SIZE + 1)
		stock[x++] = '\0';
	x = -1;
	while (strr[++x] != '\0')
		stock[x] = strr[x];
	y = 0;
	while (buf[y] != '\0')
		stock[x++] = buf[y++];
	stock[x] = '\0';
	free(strr);
	return (stock);
}

int	ft_read(char **str, int fd)
{
	int		n;
	int		rid;
	char	*strr;

	n = 1;
	rid = 1;
	if (fd < 0)
		return (fd);
	while (n > 0 && rid > 0)
	{
		strr = *str;
		n = ft_check(strr);
		if (n >= 0)
		{
			*str = ft_read_suite(fd, n, strr, &rid);
			if (*str == NULL)
				return (-1);
			n = 1;
		}
	}
	return (rid);
}

int	get_next_lineo(int fd, char **line, char **str)
{
	int			rid;

	if (!str[fd])
	{
		str[fd] = (char *)malloc(sizeof(char) * 1);
		if (!str[fd])
			return (-1);
		str[fd][0] = '\0';
	}
	rid = ft_read(&(str[fd]), fd);
	if (rid < 0)
		return (free_for_rtn(str[fd], -1));
	*line = ft_nextline(&str[fd]);
	if (*line == NULL || str[fd] == NULL)
		return (free_for_rtn(str[fd], -1));
	if (str[fd][0] == '\0' && rid == 0)
		return (0);
	return (1);
}
