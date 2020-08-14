/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:30:23 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/14 21:49:15 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_changes_params(int x, int y, t_fractal *data)
{
	if (!data->locked)
	{
		data->c.re = 4 * ((double)x /data->w - 0.5);
		data->c.im = 4 * ((double)(data->h - y) /
            data->h - 0.5) ;
		//printf(" c.re = %f  c.im= %f\n",data->c.re, data->c.im);
		calculate(data);
	}
	return (0);
}

int		keyboard(int key, t_fractal *data)
{
	if (key == 53)/*esc*/
		exit(write(1,"Bye!\n", 6));
	if (key == 123)
		data->move_x *= 1.1;
	if (key == 124)
		data->move_x /= 1.1;
	if (key == 126)
		data->move_y *= 1.1;
	if (key == 125)
		data->move_y /= 1.1;
	if (key == 49) /*space button tolock change in Julia*/
		data->locked = 1;
	if (key == 259)	 /* command button to unclock*/
		data->locked = 0;
	if (key == 46) /*m - switch to mandelbrot set*/
		data->f_ptr = mandelbrot;
	if (key == 38) /*j switch to julia set*/
		data->f_ptr = julia;
	if (key == 24 || key == 69) /*+*/
			data->iterations += 5;
	if (key == 27 || key == 78) /*-*/
		if (data->iterations >= 15)
			data->iterations -= 5;
	if (key == 8)
		data->color += 25;
	if (key == 7)
		if (data->color >= 50)
			data->color -= 25;
	calculate(data);
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fractal *data)
{
	printf("mouse:%d\n", mouse);
	//data->c.re += (double)x / 10000;
	//data->c.im += (double)y / 10000;
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
