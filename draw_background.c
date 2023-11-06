/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:54:48 by abouram           #+#    #+#             */
/*   Updated: 2023/10/30 19:57:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_round(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < (HEIGHT_SCREEN / 2))
	{
		i = 0;
		while (i < WIDTH_SCREEN)
		{
			my_mlx_pixel_put(data, i, y, 0x0dece2);
			i++;
		}
		y++;
	}
	while (y < HEIGHT_SCREEN)
	{
		i = 0;
		while (i < WIDTH_SCREEN)
		{
			my_mlx_pixel_put(data, i, y, 0x884600);
			i++;
		}
		y++;
	}
}
