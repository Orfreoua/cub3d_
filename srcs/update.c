#include "../headers/cub3d.h"

void	turn(int keycode, t_data *data)
{
	if (keycode == R_LEFT)
		data->args.player.angle -= 2;
	else if (keycode == R_RIGHT)
		data->args.player.angle += 2;
	if (data->args.player.angle < 0)
		data->args.player.angle = 360 + data->args.player.angle;
	else if (data->args.player.angle > 360)
		data->args.player.angle = data->args.player.angle - 360;
}

void	move(int keycode, t_data *data)
{
	double	tmp;

	tmp = 0.0;
	if (keycode == 97 || keycode == UP
		|| keycode == RIGHT || keycode == DOWN)
	{
		if (keycode == UP)
			tmp = (M_PI / 180) * data->args.player.angle;
		else if (keycode == 97)
			tmp = (M_PI / 180) * (data->args.player.angle + 270);
		else if (keycode == RIGHT)
			tmp = (M_PI / 180) * (data->args.player.angle + 90);
		else if (keycode == DOWN)
			tmp = (M_PI / 180) * (data->args.player.angle + 180);
		if (data->args.map.grid[(int)(data->args.player.pos.y + (sin(tmp) / 25))]
			[(int)(data->args.player.pos.x + (cos(tmp) / 25))] != '1')
		{
			data->args.player.pos.x = (data->args.player.pos.x + (cos(tmp) / 25));
			data->args.player.pos.y = (data->args.player.pos.y + (sin(tmp) / 25));
		}
	}
}

void	keycode(int keycode, t_data *data)
{
	(void)data;
	if (keycode == ESCAPE)
	{
		//ft_free_data(data);
		exit(0);
	}
	turn(keycode, data);
	move(keycode, data);
}



int	next_frame(int keycode, t_data *data)
{
	if (data->frame % 2 != 0)
	{
		data->buff2.img = mlx_new_image(data->mlx_ptr, R_WIDTH, R_HEIGHT);
		data->buff2.addr = mlx_get_data_addr(data->buff2.img, &data->buff2.bpp,
				&data->buff2.l_len, &data->buff2.endian);
		keycode(keycode, data);
		render_scene(data, &data->buff2);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buff2.img, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->buff1.img);
	}
	else
	{
		data->buff1.img = mlx_new_image(data->mlx_ptr, R_WIDTH, R_HEIGHT);
		data->buff1.addr = mlx_get_data_addr(data->buff1.img, &data->buff1.bpp,
				&data->buff1.l_len, &data->buff1.endian);
		keycode(keycode, data);
		render_scene(data, &data->buff1);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->buff1.img, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->buff2.img);
	}
	data->frame++;
	return (0);
}
