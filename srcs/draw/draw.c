/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:18:04 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 16:54:11 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	my_pixel_put(t_screen *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= R_WIDTH) && (y >= 0 && y <= R_HEIGHT))
	{
		dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
/*
void	ft_draw_col_c(t_screen *buff, int x, int len, int color)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_pixel_put(buff, x, 0 + i, color);
		i++;
	}
}

void	ft_draw_col_f(t_screen *buff, int x, int len, int color)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_pixel_put(buff, x, (R_HEIGHT / 2) + i, color);
		i++;
	}
}*/

unsigned int	get_pixel(t_data *data, t_texture *texture, int w_pix, int w_size)
{
	int	x;
	int	y;
	int	diff;

	x = (int)nearbyint(calculate_hit_decimal(data) * (double)texture->img_width);
	y = (int)nearbyint(((double)w_pix / (double)w_size) * texture->img_height);
	diff = (data->ray.wall_height - R_HEIGHT);
	if (data->ray.wall_height > R_HEIGHT)
		y = (int)nearbyint(((double)(w_pix + diff / 2)
					/ (double)data->ray.wall_height) * texture->img_height);
	return (*(unsigned int *)(texture->addr + (y * texture->line_lenght
			+ x * (texture->bpp / 8))));
}

void	draw_textured_column(t_data *data, t_screen *buff, int x, int y)
{
	int				i;
	t_texture			*texture;
	unsigned int	color;

	i = 0;
	texture = choose_texture(data);
	while (i < data->ray.floored_wall_height)
	{
		color = get_pixel(data, texture, i, data->ray.floored_wall_height);
		my_pixel_put(buff, x, y + i, color);
		i++;
	}
}
