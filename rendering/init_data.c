/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:49:39 by abouram           #+#    #+#             */
/*   Updated: 2023/11/13 08:39:38 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	data_init(t_data *data)
{
	data->is_up = 0;
	data->is_down = 0;
	data->is_left = 0;
	data->is_right = 0;
	data->h = 0;
	data->v = 0;
	data->x = data->call->finalx;
	data->y = data->call->finaly;
}
