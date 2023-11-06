/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dda_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:46:28 by abouram           #+#    #+#             */
/*   Updated: 2023/10/27 16:25:05 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	line(t_data *data, float new_x, float new_y, int color)
{
	double	deltax;
	double	deltay;
	int		i;
	double	step;

	i = 0;
	data->x = data->call->finalx;
	data->y = data->call->finaly;
	deltax = (new_x - data->x);
	deltay = (new_y - data->y);
	step = (fabs(deltax) + fabs(deltay));
	deltax = deltax / step;
	deltay = deltay / step;
	while (i <= step)
	{
		my_mlx_pixel_put(data, data->x, data->y, color);
		data->x += deltax;
		data->y += deltay;
		i++;
	}
}
