/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:16 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/09 17:11:02 by aelphias         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* for every pixel, iterate znew = zold² + c 
on the complex plane until it leaves the circle around the origin 
with radius 2. The number of iterations it the color of the pixel. */
/* void	compt_complex(t_fractal *data)
{
	

	
}
 */

void	calculate(t_fractal *data)
{
	int i;
	int	k;

	i = 0;
	/* data->x = 20;
	data->y = 50;
	data->x_cmplx =  -2 + data->x *(4 / data->w);
	data->y_cmplx =  2 - data->y * (4 / data->h);
 */
	//mlx_pixel_put(data->mlx_ptr, data->win_ptr, 1, 1, 0xFF5733);
	
	

	int deph = 32, width = data->w, endian = 0;

	data->mlx_img = mlx_new_image(data->mlx_ptr, data->w, data->h);
	data->mlx_addr = (unsigned int*)mlx_get_data_addr(data->mlx_img, &deph, &width, &endian);

	int x = 0, y = 0;
	while (data->y != data->h) {
		while (data->x != data->w) {
			data->mlx_addr[data->x + data->w * data->y] = 20;
			data->x += 1;
		}
		data->x = 0;
		data->y += 1;
	}

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0 ,0);
}
