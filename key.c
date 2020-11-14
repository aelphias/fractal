/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:58:57 by mellie            #+#    #+#             */
/*   Updated: 2020/11/12 21:04:25 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_changes_params(int x, int y, t_fractal *data)
{
	if (!data->locked)
	{
		data->c.re = 4 * ((double)x / data->w - 0.5);
		data->c.im = 4 * ((double)(data->h - y) /
		data->h - 0.5);
		calculate(data);
	}
	return (0);
}

int	keyboard(int key, t_fractal *data)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		data->move_x += 0.1*(250/data->zoom);
	if (key == 124)
		data->move_x -= 0.1*(250/data->zoom);
	if (key == 126)
		data->move_y += 0.1*(250/data->zoom);
	if (key == 125)
		data->move_y -= 0.1*(250/data->zoom);
	if (key == 49)
		data->locked = 1;
	if (key == 259)
		data->locked = 0;
	if (key == 46)
		data->f_ptr = mandelbrot;
	if (key == 38)
		data->f_ptr = julia;
	if (key == 11)
		data->f_ptr = burningship;
	keyboard_1(key, data);
	calculate(data);
	return (0);
}

int	keyboard_1(int key, t_fractal *data)
{
	if (key == 24 || key == 69)
		data->iterations += 5;
	if (key == 27 || key == 78)
		if (data->iterations >= 15)
			data->iterations -= 5;
	if (key == 8)
		data->color += 25;
	if (key == 7)
		if (data->color > 50)
			data->color -= 25;
    if (key == 6)
        ft_reset(data);
	return (0);
}

int	deal_mouse(int mouse, int x, int y, t_fractal *data)
{
	t_complex p0;
	t_complex p1;

	if (mouse == 4)
	{
		p0.re = (x - data->w / 2) / data->zoom + data->move_x;
		p0.im = (y - data->h / 2) / data->zoom + data->move_y;
		p1.re = (x - data->w / 2) / data->zoom * 1.1 + data->move_x;
		p1.im = (y - data->h / 2) / data->zoom * 1.1 + data->move_y;
		data->move_x += p1.re - p0.re;
		data->move_y += p1.im - p0.im;
		data->zoom *= 1.1;
	}
	if (mouse == 5)
	{
		p0.re = (x - data->w / 2) / data->zoom + data->move_x;
		p0.im = (y - data->h / 2) / data->zoom + data->move_y;
		p1.re = (x - data->w / 2) / data->zoom / 1.1 + data->move_x;
		p1.im = (y - data->h / 2) / data->zoom / 1.1 + data->move_y;
		data->move_x += p1.re - p0.re;
		data->move_y += p1.im - p0.im;
		data->zoom /= 1.1;
	}
	calculate(data);
	return (0);
}
