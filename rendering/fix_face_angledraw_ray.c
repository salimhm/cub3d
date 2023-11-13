/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_face_angledraw_ray.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:14:56 by abouram           #+#    #+#             */
/*   Updated: 2023/11/13 08:39:15 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fix_r_angle(t_data *data)
{
	if (data->call->retation_angle < 0)
		data->call->retation_angle += (2 * M_PI);
	else if (data->call->retation_angle > 2 * M_PI)
		data->call->retation_angle -= (2 * M_PI);
	if (data->call->r_angle < 0)
		data->call->r_angle += (2 * M_PI);
	else if (data->call->r_angle > 2 * M_PI)
		data->call->r_angle -= (2 * M_PI);
}

void	face_angel(t_data *data)
{
	if (data->call->r_angle > 0 && data->call->r_angle < M_PI)
		data->is_down = 1;
	else if (!(data->call->r_angle > 0 && data->call->r_angle < M_PI))
		data->is_up = 1;
	if (data->call->r_angle < M_PI / 2 || data->call->r_angle > 3 * M_PI / 2)
		data->is_right = 1;
	else if (!(data->call->r_angle < M_PI_2 || data->call->r_angle > 3 * M_PI
			/ 2))
		data->is_left = 1;
}

void	print_rays(t_data *data)
{
	int	i;

	i = 0;
	data->call->r_angle = data->call->retation_angle - (M_PI / 6);
	while (i < WIDTH_SCREEN)
	{
		horizontal_or_vertical(data);
		data->call->r_angle += ((2 * M_PI / 6) / (WIDTH_SCREEN));
		i++;
	}
}
