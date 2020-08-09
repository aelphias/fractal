/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:18:48 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/09 20:51:41 by aelphias         ###   ########lyon.fr   */
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

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	unsigned int	*mlx_addr;
	int			color;
	int			x;
	int			y;
	int			z;
	int			i;
	int			k;
	int			w;
	int			h;
	float		x_cmplx;
	float		y_cmplx;
}		t_fractal;

void	set_defaults(t_fractal *data);
void	calculate(t_fractal *data);
int		ft_exit(t_fractal *data);
int		deal_key(int key, t_fractal *data);

#endif
