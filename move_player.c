/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:34:34 by abouram           #+#    #+#             */
/*   Updated: 2023/10/27 17:55:45 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_awall(t_data *data, double newx, double newy)
{
	if (data->call->map[(int)newy / HEIGHT][(int)newx / WIDTH] != '1'
		&& data->call->map[(int)newy / HEIGHT][(int)data->call->new_x
		/ WIDTH] != '1' && data->call->map[(int)data->call->new_y
		/ HEIGHT][(int)newx / WIDTH] != '1')
	{
		data->call->new_x = newx;
		data->call->new_y = newy;
		draw_player(data, data->call->new_y, data->call->new_x);
	}
}

void	move_player_c(t_data *data, int keycode, double newx, double newy)
{
	if (keycode == 123)
	{
		newx = data->call->new_x + (MOVESPEED * cos(data->call->retation_angle
					- M_PI / 2));
		newy = data->call->new_y + (MOVESPEED * sin(data->call->retation_angle
					- M_PI / 2));
		is_awall(data, newx, newy);
	}
	if (keycode == 124)
	{
		newx = data->call->new_x + (MOVESPEED * cos(data->call->retation_angle
					+ M_PI / 2));
		newy = data->call->new_y + (MOVESPEED * sin(data->call->retation_angle
					+ M_PI / 2));
		is_awall(data, newx, newy);
	}
	if (keycode == 2)
	{
		data->call->retation_angle += ROTATION;
		draw_player(data, data->call->new_y, data->call->new_x);
	}
}

void	move_player(t_data *data, int keycode)
{
	if (keycode == 13)
	{
		data->newx = data->call->new_x + (MOVESPEED
				* cos(data->call->retation_angle));
		data->newy = data->call->new_y + (MOVESPEED
				* sin(data->call->retation_angle));
		is_awall(data, data->newx, data->newy);
	}
	if (keycode == 1)
	{
		data->newx = data->call->new_x - (MOVESPEED
				* cos(data->call->retation_angle));
		data->newy = data->call->new_y - (MOVESPEED
				* sin(data->call->retation_angle));
		is_awall(data, data->newx, data->newy);
	}
	if (keycode == 0)
	{
		data->call->retation_angle -= ROTATION;
		draw_player(data, data->call->new_y, data->call->new_x);
	}
	move_player_c(data, keycode, data->newx, data->newy);
}
