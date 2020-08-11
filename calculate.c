/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:16 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/11 14:47:31 by aelphias         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
 
__uint32_t	bernstein_color(int iter, int itera, double shift)
{
	__uint32_t	color;   /*0 .. 4,294,967,295*/
	int			r;
	int			g;
	int			b;
	double		t;

	color = 0;
	if (itera == 0)
		return (0);
	t = fabs(shift - ((double)(iter) / (double)(itera)));
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

int	mandelbrot(t_fractal *data)
{
	int i = 0;
	t_complex	z, c;
	double zoom;

	zoom = 250.0;
				/*move left and write*/
	c.re = (data->x - 400) / zoom;//zoom;
	c.im = (data->y - 400) / zoom; /* move up and down*/
	z = c;
	while (i < 200 && ((z.re * z.re + z.im * z.im) <= 4.f)) {
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += c.re;
		z.im += c.im;
		i += 1;
	}
/* 	return (bernstein_color(i, 2000, 0.00775)); // color 0,1 - 1
 */	return (i); // color 0,1 - 1

}

int	julia(t_fractal *data)
{
	int i = 0;
	t_complex	z, c;

	z.re = (data->x - 400) / 400.f;
	z.im = (data->y - 400) / 400.f;
	c.re = -0.4;
	c.im = 0.6;
	while (i < 10000 && ((z.re * z.re + z.im * z.im) <= 4.f)) {
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += c.re;
		z.im += c.im;
		i += 1;
	}
	return (i);
	//return (bernstein_color(i, 2000, 0.00775));
}

void	calculate(t_fractal *data)
{
	int deph = 32, width = data->w, endian = 0;

	data->mlx_img = mlx_new_image(data->mlx_ptr, data->w, data->h);
	data->mlx_addr = (unsigned int*)mlx_get_data_addr(data->mlx_img, &deph, &width, &endian);
	while (data->y != data->h) {
		while (data->x != data->w) {
			data->mlx_addr[data->x + data->w * data->y] = mandelbrot(data);
			data->x += 1;
		}
		data->x = 0;
		data->y += 1;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0 ,0); 
}
