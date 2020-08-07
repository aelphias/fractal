/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:53:31 by aelphias          #+#    #+#             */
/*   Updated: 2020/08/07 21:53:57 by aelphias         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(t_fractal *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}