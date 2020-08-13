/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:16 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/14 00:55:10 by aelphias         ###   ########.fr       */
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

int	m(t_fractal *data)
{
	unsigned int i;
	t_complex	z;
	t_complex	c;
	
	i = 0;
	c.re = ((data->x - 400) / data->zoom) + data->move_x;//zoom;
	c.im = ((data->y - 400) / data->zoom) + data->move_y; /* move up and down*/
	z = c;
	while (i < data->iterations && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += c.re;
		z.im += c.im;
		i++;
	}
	//return (bernstein_color(i, 100, 0.5)); // color 0,1 - 1
	return (i * 4); // color 0,1 - 1
}

int	j(t_fractal *data)
{
	unsigned int i;
	t_complex	z;

	i = 1;
	z.re = ((data->x - 400) / data->zoom);
	z.im = ((data->y - 400) / data->zoom);
	while (i < 500 && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += data->c.re;
		z.im += data->c.im;
		i++;
	}
	//return (i);
	return (bernstein_color(i, 2000, 0.00775));
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
