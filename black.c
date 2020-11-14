/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:49:27 by mellie            #+#    #+#             */
/*   Updated: 2020/11/12 20:50:31 by mellie           ###   ########.fr       */
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}
