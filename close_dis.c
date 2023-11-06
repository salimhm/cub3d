/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_dis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:52:14 by abouram           #+#    #+#             */
/*   Updated: 2023/10/29 22:51:11 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void get_horizontal(t_data *data, double h_x, double h_y)
{
		data->horizontalx = h_x;
		data->horizontaly = h_y;
}

void get_vertical(t_data *data)
{
		data->verticalx = data->incrmentx;
		data->verticaly = data->incrmenty;
}

double	close_dis(t_data *data, double h_x, double h_y)
{
	if (data->h_hit == 1)
		data->h = sqrt(((h_x - data->x) * (h_x - data->x)) + ((h_y - data->y)
					* (h_y - data->y)));
	else
		data->h = 2147483647;
	if (data->v_hit == 1)
		data->v = sqrt((data->incrmentx - data->x) * (data->incrmentx - data->x)
				+ (data->incrmenty - data->y) * (data->incrmenty - data->y));
	else
		data->v = 2147483647;
	if (data->h < data->v)
	{
		get_horizontal(data, h_x, h_y);
		line(data, h_x, h_y, 0x4ec5cf);
		return (data->h);
	}
	else
	{
		get_vertical(data);
		line(data, data->incrmentx, data->incrmenty, 0x4ec5cf);
		return (data->v);
	}
}
