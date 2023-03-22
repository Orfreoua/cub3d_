/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:22:53 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 16:48:16 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	load_textures(t_data *data, t_args *args)
{
	args->east.img = mlx_xpm_file_to_image(data->mlx_ptr, args->north.path,
			&args->east.img_width, &args->east.img_height);
	args->south.img = mlx_xpm_file_to_image(data->mlx_ptr, args->south.path,
			&args->south.img_width, &args->south.img_height);
	args->west.img = mlx_xpm_file_to_image(data->mlx_ptr, args->east.path,
			&args->west.img_width, &args->west.img_height);
	args->north.img = mlx_xpm_file_to_image(data->mlx_ptr, args->west.path,
			&args->north.img_width, &args->north.img_height);
	if (!args->east.img || !args->south.img
		|| !args->west.img || !args->north.img)
		return (KO);
	args->east.addr = mlx_get_data_addr(args->east.img, &args->east.bpp,
			&args->east.line_lenght, &args->east.endian);
	args->south.addr = mlx_get_data_addr(args->south.img, &args->south.bpp,
			&args->south.line_lenght, &args->south.endian);
	args->west.addr = mlx_get_data_addr(args->west.img, &args->west.bpp,
			&args->west.line_lenght, &args->west.endian);
	args->north.addr = mlx_get_data_addr(args->north.img, &args->north.bpp,
			&args->north.line_lenght, &args->north.endian);
	return (OK);
}

double	calculate_hit_decimal(t_data *data)
{
	double	hit;

	if (data->args.player.dir == 'e')
		hit = data->args.player.f_hit.y - (int)data->args.player.f_hit.y;
	else if (data->args.player.dir == 'n')
		hit = data->args.player.f_hit.x - (int)data->args.player.f_hit.x;
	else if (data->args.player.dir == 'w')
		hit = (int)data->args.player.f_hit.y + 1 - data->args.player.f_hit.y;
	else if (data->args.player.dir == 's')
		hit = (int)data->args.player.f_hit.x + 1 - data->args.player.f_hit.x;
	else
		hit = 0.0;//error
	return (hit);
}

unsigned int	ft_get_M_PIxel(t_data *data, t_texture *texture, int w_M_PIx, int w_size)
{
	int	x;
	int	y;
	int	diff;

	x = (int)nearbyint(calculate_hit_decimal(data) * (double)texture->img_width);
	y = (int)nearbyint(((double)w_M_PIx / (double)w_size) * texture->img_height);
	diff = (data->ray.wall_height - R_HEIGHT);
	if (data->ray.wall_height > R_HEIGHT)
		y = (int)nearbyint(((double)(w_M_PIx + diff / 2)
					/ (double)data->ray.wall_height) * texture->img_height);
	return (*(unsigned int *)(texture->addr + (y * texture->line_lenght
			+ x * (texture->bpp / 8))));
}

t_texture	*choose_texture(t_data *data)
{
	if (data->args.player.dir == 'e')
		return (&data->args.east);
	else if (data->args.player.dir == 's')
		return (&data->args.south);
	else if (data->args.player.dir == 'w')
		return (&data->args.west);
	else if (data->args.player.dir == 'n')
		return (&data->args.north);
	return (NULL);
}
