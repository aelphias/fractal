/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:30:23 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/12 22:22:50 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard(int key, t_fractal *data)
{
	
	if (key == 53)
	{
		write(1, "Bye!\n",5);	
	 	exit(0);
	}
	if (key == 34) // i - in
	{	
		data->f_ptr = m;
		//data->zoom += 30;
		black_it(data);
	    calculate(data);
	}
		if (key == 31) // o - out
	{
		data->f_ptr = j;
		//data->zoom -= 30;
		black_it(data);
	    calculate(data);
	}
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fractal *data)
{

	data->move_x += ((x - 400) / data->zoom  + data->move_x)
			- ((x - 400) / (data->zoom * 1.1) + data->move_x);
	data->move_y += ((y - 400) / data->zoom  + data->move_y)
			- ((y - 400) / (data->zoom * 1.1) + data->move_y);

	if (mouse == 5)
		data->zoom *= 1.1;

	calculate(data);
	return (0);
}
