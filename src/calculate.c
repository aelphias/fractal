/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:16 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/14 22:21:13 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
 
__uint32_t	bernstein_color(int i, int i_max)
{
	__uint32_t	color;   /*0 .. 4,294,967,295*/
	int			r;
	int			g;
	int			b;
	double		t;

	color = 0;
	if (i_max == 0)
		return (0);
	t = fabs(((double)(i) / (double)(i_max)));
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

int burningship(t_fractal *data)
{
	unsigned int i;
	t_complex	z;
	t_complex	c;
	t_complex tmp;

	i = 0;
	c.re = ((data->x - 400) / data->zoom) + data->move_x;//zoom;
	c.im = ((data->y - 400) / data->zoom) + data->move_y; /* move up and down*/
	z = c;
	while (i < data->iterations && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = fabs(2 * tmp.re * tmp.im);
		z.re += c.re;
		z.im += c.im;
		i++;
	}
		return (bernstein_color(i, data->color));
}

int	mandelbrot(t_fractal *data)
{
	unsigned int i;
	t_complex	z;
	t_complex	c;
	t_complex tmp;

	i = 0;
	c.re = ((data->x - 400) / data->zoom) + data->move_x;//zoom;
	c.im = ((data->y - 400) / data->zoom) + data->move_y; /* move up and down*/
	z = c;
	while (i < data->iterations && ((z.re * z.re + z.im * z.im) <= 4.f))
	{

		tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += c.re;
		z.im += c.im;
		i++;
	}
	return (bernstein_color(i, data->color)); // color 0,1 - 1
}

int	julia(t_fractal *data)
{
	unsigned int i;
	t_complex	z;
	t_complex tmp;

	i = 0;
	z.re = ((data->x - 400) / data->zoom) + data->move_x;
	z.im = ((data->y - 400) / data->zoom) + data->move_y;
	while (i < data->iterations && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += data->c.re;
		z.im += data->c.im;
		i++;
	}
	return (bernstein_color(i, data->color));
}

void	calculate(t_fractal *data)
{	
	black_it(data);
	while (data->y != data->h)
	{
		while (data->x != data->w)
		{
			data->mlx_addr[data->x + data->w * data->y] = data->f_ptr(data);
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	data->y = 0;
	data->x = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0 ,0);
}
