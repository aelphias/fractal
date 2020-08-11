/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:30:23 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/12 01:22:15 by aelphias         ###   ########lyon.fr   */
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
		data->zoom += 30;
		black_it(data);
	    calculate(data);
	}
		if (key == 31) // o - out
	{
		data->zoom -= 30;
		black_it(data);
	    calculate(data);
	}
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_fractal *data)
{
	if (mouse == 5)
		data->zoom += 20;
	if (mouse == 4 )
		data->zoom -= 20;
	calculate(data);
	return (0);
}
