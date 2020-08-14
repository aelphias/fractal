/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:06:51 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/14 23:19:31 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_fractal *data)
{
	int		depth;
	int		width;
	int		endian;

	ft_bzero(data, sizeof(t_fractal));
	depth = 24;
	endian = 0;
	width = data->w;
	data->w = 800;
	data->h = 800;
	data->zoom = 250.0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w, data->h, "Fractal");
	data->mlx_img = mlx_new_image(data->mlx_ptr, data->w, data->h);
	data->mlx_addr =
	(unsigned int*)mlx_get_data_addr(data->mlx_img, &depth, &width, &endian);
}

void	mlx_start(t_fractal *data)
{
	mlx_mouse_hook(data->win_ptr, deal_mouse, data);
	mlx_hook(data->win_ptr, 2, 0, keyboard, data);
	mlx_hook(data->win_ptr, 6, 0, mouse_changes_params, data);
	mlx_loop(data->mlx_ptr);
}

void	check(char **argv, t_fractal *data)
{
	if (argv[1][0] == 'm')
	{
		data->f_ptr = mandelbrot;
		data->iterations = 150;
		data->color = 250;
		calculate(data);
	}
	else if (argv[1][0] == 'j')
	{
		data->f_ptr = julia;
		data->c.re = -0.5;
		data->c.im = 0.5;
		data->iterations = 50;
		data->color = 250;
		calculate(data);
	}
	else if (argv[1][0] == 'b')
	{
		data->f_ptr = burningship;
		data->iterations = 50;
		data->color = 50;
		calculate(data);
	}
}

int		main(int argc, char **argv)
{
	t_fractal data;

	if (argc < 2)
	{
		write(2, "usage: ./fractol [flag]\nm - mandelbrot set\n"
		"j julia set\nr - 3rd set\n", 67);
		return (1);
	}
	if (argv[1][0] != 'm' && argv[1][0] != 'j' && argv[1][0] != 'b')
	{
		write(2, "wrong flag, try: m or j or b\n", 27);
		return (2);
	}
	set_defaults(&data);
	check(argv, &data);
	mlx_start(&data);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	return (0);
}
