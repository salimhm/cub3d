/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:44:21 by abouram           #+#    #+#             */
/*   Updated: 2023/10/28 22:38:46 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data, double x, double y)
{
	data->call->finalx = y;
	data->call->finaly = x;
	// my_mlx_pixel_put(data, x, y, 0xc0392b);
}
