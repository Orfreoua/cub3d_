/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:58:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/22 17:12:52 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_turn(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->args.player.angle -= 2;
	else if (keycode == 65363)
		data->args.player.angle += 2;
	if (data->args.player.angle < 0)
		data->args.player.angle = 360 + data->args.player.angle;
	else if (data->args.player.angle > 360)
		data->args.player.angle = data->args.player.angle - 360;
}

void	ft_move(int keycode, t_data *data)
{
	double	tmp;

	tmp = 0.0;
	if (keycode == 97 || keycode == 119
		|| keycode == 100 || keycode == 115)
	{
		if (keycode == 119)
			tmp = (M_PI / 180) * data->args.player.angle;
		else if (keycode == 97)
			tmp = (M_PI / 180) * (data->args.player.angle + 270);
		else if (keycode == 100)
			tmp = (M_PI / 180) * (data->args.player.angle + 90);
		else if (keycode == 115)
			tmp = (M_PI / 180) * (data->args.player.angle + 180);
		if (data->args.map.grid[(int)(data->args.player.pos.y + (sin(tmp) / 25))]
			[(int)(data->args.player.pos.x + (cos(tmp) / 25))] != '1')
		{
			data->args.player.pos.x = (data->args.player.pos.x + (cos(tmp) / 25));
			data->args.player.pos.y = (data->args.player.pos.y + (sin(tmp) / 25));
		}
	}
}

void	ft_keycode(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 65307)
	{
		//ft_free_data(data);
		exit(0);
	}
	ft_turn(keycode, data);
	ft_move(keycode, data);
}



int	ft_next_frame(int keycode, t_data *data)
{
	if (data->frame % 2 != 0)
	{
		data->buff2.img = mlx_new_image(data->mlx_ptr, R_WIDTH, R_HEIGHT);
		data->buff2.addr = mlx_get_data_addr(data->buff2.img, &data->buff2.bpp,
				&data->buff2.l_len, &data->buff2.endian);
		ft_keycode(keycode, data);
		render_scene(data, &data->buff2);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buff2.img, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->buff1.img);
	}
	else
	{
		data->buff1.img = mlx_new_image(data->mlx_ptr, R_WIDTH, R_HEIGHT);
		data->buff1.addr = mlx_get_data_addr(data->buff1.img, &data->buff1.bpp,
				&data->buff1.l_len, &data->buff1.endian);
		ft_keycode(keycode, data);
		render_scene(data, &data->buff1);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buff1.img, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->buff2.img);
	}
	data->frame++;
	return (0);
}

int	load_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (load_textures(data, &data->args) == KO)
		return (KO);
	data->win_ptr = mlx_new_window(data->mlx_ptr, R_WIDTH, R_HEIGHT, "");
	data->buff1.img = mlx_new_image(data->mlx_ptr, R_WIDTH, R_HEIGHT);
	data->buff1.addr = mlx_get_data_addr(data->buff1.img, &data->buff1.bpp,
			&data->buff1.l_len, &data->buff1.endian);
	render_scene(data, &data->buff1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buff1.img, 0, 0);
	//mlx_hook(data->win_ptr, 33, (1L << 17), ft_exit, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_next_frame, data);
	mlx_loop(data->mlx_ptr);
	return (OK);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.frame = 1;
	(void)argc;
	(void)argv;
	not_real_data(&data);
	if (load_game(&data) == KO)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
