/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:09:02 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/12 15:29:47 by aelphias         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	black_it(t_fractal *data)
{	
	int	x;
	int	y;
	
	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			data->mlx_addr[data->x + data->w * data->y] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0 ,0);
}