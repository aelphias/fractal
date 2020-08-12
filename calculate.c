/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:16 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/12 22:16:08 by aelphias         ###   ########.fr       */
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
	int i = 0;
	t_complex	z, c;
				/*move left and write*/
	/* c.re = (data->x - (data->w / 2)* data->mouse_x) / data->zoom;//zoom;
	c.im = (data->y - (data->h /2 )* data->mouse_y) / data->zoom; */
	c.re = ((data->x - 400) / data->zoom) + data->move_x;//zoom;
	c.im = ((data->y - 400) / data->zoom) + data->move_y; /* move up and down*/
	z = c;

	
	while (i < 20 && ((z.re * z.re + z.im * z.im) <= 4.f))
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

int	j(t_fractal *data)
{
	int i;
	t_complex	z;

	i = 0;
	z.re = (data->x - 400) / 400.f;
	z.im = (data->y - 400) / 400.f;
	while (i < 10000 && ((z.re * z.re + z.im * z.im) <= 4.f))
	{
		t_complex tmp = z;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im;
		z.im = 2 * tmp.re * tmp.im;
		z.re += data->c.re;
		z.im += data->c.im;
		i += 1;
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


/* int mandel(complex c, int max_count) {
 int count = 0; complex z = 0;
 for (int i = 0; i < max_count; ++i) {
 if (abs(z) >= 2.0) break;
 z = z*z + c; count++;
 }
 return count;
}  */