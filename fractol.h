/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:10:56 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/14 01:53:03 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <complex.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_fractal	t_fractal;

typedef struct				s_complex
{
	double re;
	double im;
}							t_complex;


struct						s_fractal
{
	unsigned int	*mlx_addr;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	int				color;
	int				x;
	int				y;
	int				z;
	int				i;
	int				k;
	int				w;
	int				h;
	double			zoom;
	t_complex		c;
	char			fractal_type;
	double			move_x;
	double			move_y;
	int				(*f_ptr)(t_fractal*);
	unsigned int	iterations;
	short			locked;
};

void						set_defaults(t_fractal *data);
void						calculate(t_fractal *data);
int							ft_exit(t_fractal *data);
int							keyboard(int key, t_fractal *data);
int							deal_mouse(int mouse,
								int x, int y, t_fractal *data);
int							julia(t_fractal *data);
int							mandelbrot(t_fractal *data);
int							burningship(t_fractal *data);
void						black_it(t_fractal *data);
int	mouse_changes_params(int x, int y, t_fractal *data);
#endif
