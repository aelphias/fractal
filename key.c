/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:30:23 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/14 00:49:37 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_changes_params(int x, int y, t_fractal *data)
{
	data->c.re += (double)x / 10000;
	data->c.im += (double)y / 10000;
	calculate(data);
	return (0);
}

int		keyboard(int key, t_fractal *data)
{
	printf("key:%d\n", key);
	
	if (key == 53)/*esc*/
		exit(write(1,"Bye!\n", 6));
	if (key == 46) /*m - switch to mandelbrot set*/
		data->f_ptr = m;
	if (key == 38) /*j switch to julia set*/
		data->f_ptr = j;
	if (key == 24 || key == 69) /*+*/
			data->iterations += 100;
	if (key == 27 || key == 78) /*-*/
		if (data->iterations >= 125)
			data->iterations -= 100;
	printf("iterations:%d", data->iterations);
	calculate(data);
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fractal *data)
{
	printf("mouse:%d\n", mouse);
	printf(" mouse x =%d\n mouse y=%d\n",x,y);
	data->c.re += (double)x / 10000;
	data->c.im += (double)y / 10000;
	if (mouse == 5)
	{
		data->zoom *= 1.1;
		data->move_x += ((x - 400) / data->zoom  + data->move_x)
			- ((x - 400) / (data->zoom * 1.1) + data->move_x);
		data->move_y += ((y - 400) / data->zoom  + data->move_y)
			- ((y - 400) / (data->zoom * 1.1) + data->move_y);
	}
	if (mouse == 4)
	{
		data->zoom /= 1.1;
		data->move_x += ((x - 400) / data->zoom  + data->move_x)
			- ((x - 400) / (data->zoom / 1.1) + data->move_x);
		data->move_y += ((y - 400) / data->zoom  + data->move_y)
			- ((y - 400) / (data->zoom / 1.1) + data->move_y);
	}
	calculate(data); 
	return (0);
}
