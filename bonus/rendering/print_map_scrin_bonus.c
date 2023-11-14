/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_scrin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:16:12 by abouram           #+#    #+#             */
/*   Updated: 2023/10/26 23:16:13 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_player(t_data *data, int x)
{
	int static	i;
	char		direction;

	direction = data->call->map[(int)x / HEIGHT][(int)data->call->x / WIDTH];
	if (direction == 'N' || direction == 'W' || direction == 'S'
		|| direction == 'E')
	{
		my_mlx_pixel_put(data, data->call->x, x, 0xffffff);
		data->call->px = (double)x;
		data->call->py = (double)data->call->x;
		if (i == 0 && direction == 'N')
			data->call->retation_angle = -M_PI / 2;
		else if (i == 0 && direction == 'W')
			data->call->retation_angle = M_PI;
		else if (i == 0 && direction == 'S')
			data->call->retation_angle = M_PI / 2;
		else if (i == 0 && direction == 'E')
			data->call->retation_angle = 0;
		i++;
	}
}

void	print_map(t_data *data)
{
	int	x;

	x = 0;
	while (x < (HEIGHT * data->call->j))
	{
		data->call->x = 0;
		while (data->call->x < (WIDTH * data->call->i))
		{
			if (data->call->map[(int)x / HEIGHT] && data->call->map[(int)x
					/ HEIGHT][(int)data->call->x / WIDTH] == '\0')
				break ;
			else if (data->call->map[(int)x / HEIGHT] && data->call->map[(int)x
					/ HEIGHT][(int)data->call->x / WIDTH] == '0')
				my_mlx_pixel_put(data, data->call->x, x, 0xffffff);
			else if (data->call->map[(int)x / HEIGHT] && data->call->map[(int)x
					/ HEIGHT][(int)data->call->x / WIDTH] == '1')
				my_mlx_pixel_put(data, data->call->x, x, 0xcf9c4e);
			print_player(data, x);
			data->call->x++;
		}
		x++;
	}
}
