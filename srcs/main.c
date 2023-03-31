/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:58:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/31 19:42:45 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
	mlx_hook(data->win_ptr, 2, 1L << 0, next_frame, data);
	mlx_loop(data->mlx_ptr);
	return (OK);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error(BAD_NB_ARG));
		if (load_file(&data, argv[1]) == ERROR)
		return (EXIT_FAILLURE);
	data.frame = 1;
	not_real_data(&data);
	//if (load_game(&data) == KO)
	//	return (EXIT_FAILURE);
	free_all_nxt(&data);
	return (EXIT_SUCCESS);
}
