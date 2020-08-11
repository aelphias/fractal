/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:16 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/12 01:31:15 by aelphias         ###   ########lyon.fr   */
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
				/*move left and write*/
	c.re = (data->x - 350) / data->zoom;//zoom;
	c.im = (data->y - 250) / data->zoom; /* move up and down*/
	z = c;
	while (i < 300 && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += c.re;
		z.im += c.im;
		i += 1;
	}
	//return (bernstein_color(i, 100, 0.5)); // color 0,1 - 1
	return (i * 4); // color 0,1 - 1

}

int	julia(t_fractal *data)
{
	int i;
	t_complex	c;
	t_complex	z;

	i = 0;
	z.re = (data->x - 400) / 400.f;
	z.im = (data->y - 400) / 400.f;
	c.re = -0.4;
	c.im = 0.6;
	while (i < 10000 && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += c.re;
		z.im += c.im;
		i += 1;
	}
	//return (i);
	return (bernstein_color(i, 2000, 0.00775));
}

void	calculate(t_fractal *data)
{	
	int (*f_ptr)(t_fractal*); 
	
  	f_ptr  = &mandelbrot;
	black_it(data);
	while (data->y != data->h)
	{
		while (data->x != data->w)
		{
			data->mlx_addr[data->x + data->w * data->y] = (*f_ptr)(data);
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	data->y = 0;
	data->x = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0 ,0);
}


/* int mandel(complex c, int max_count) {
 int count = 0; complex z = 0;
 for (int i = 0; i < max_count; ++i) {
 if (abs(z) >= 2.0) break;
 z = z*z + c; count++;
 }
 return count;
}  */