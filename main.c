/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:06:51 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/12 01:25:53 by aelphias         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Value	Description
0x00000000	Black
0x00FF0000	Bright Red
0x0000FF00	Bright Green
0x000000FF	Bright Blue
0x007F7F7F	Gray
0x00FFFF00	Bright Yellow
0x00FF7F7F	Red Pastel
0x00FFFFFF	White */

void	set_defaults(t_fractal *data)
{
	int		depth;
	int		width; 
	int		endian;
	
	depth 		= 24;
	width		= data->w;
	endian		= 0;
	bzero(data, sizeof(t_fractal));
	data->w = 800; /* x */
	data->h = 800;/* y */
	data->zoom = 400.0;
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
	mlx_loop(data->mlx_ptr);
}

int	main(void)
{
	t_fractal *data;
	
	set_defaults(data);
	calculate(data); 
	mlx_start(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}