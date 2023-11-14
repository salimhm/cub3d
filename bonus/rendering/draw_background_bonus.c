/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:54:48 by abouram           #+#    #+#             */
/*   Updated: 2023/11/14 12:04:03 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_rgb_floor(t_data *data, t_texture_fc *floor_n_ceiling,
		char **floor, int i)
{
	char	*color;

	if (data->call->elements[i][0] == 'F')
	{
		color = remove_spaces(data->call->elements[i]);
		floor = ft_split(color, ',');
		floor_n_ceiling->r_f = ft_atoi(floor[2]);
		floor_n_ceiling->g_f = ft_atoi(floor[1]);
		floor_n_ceiling->b_f = ft_atoi(floor[0]);
		free2d(floor);
		free(color);
	}
}

void	get_rgb(t_data *data, t_texture_fc *floor_n_ceiling)
{
	char	**ceiling;
	char	**floor;
	char	*color;
	int		i;

	floor = NULL;
	i = -1;
	while (data->call->elements[++i])
	{
		if (data->call->elements[i][0] == 'C')
		{
			color = remove_spaces(data->call->elements[i]);
			ceiling = ft_split(color, ',');
			floor_n_ceiling->r_c = ft_atoi(ceiling[2]);
			floor_n_ceiling->g_c = ft_atoi(ceiling[1]);
			floor_n_ceiling->b_c = ft_atoi(ceiling[0]);
			free2d(ceiling);
			free(color);
		}
		check_rgb_floor(data, floor_n_ceiling, floor, i);
	}
}

void	print_round(t_data *data)
{
	int				i;
	int				y;
	t_texture_fc	floor_n_ceiling;

	get_rgb(data, &floor_n_ceiling);
	i = -1;
	y = -1;
	while (++y < (HEIGHT_SCREEN / 2))
	{
		i = -1;
		while (++i < WIDTH_SCREEN)
			my_mlx_pixel_put(data, i, y, create_trgb(0, floor_n_ceiling.r_c,
					floor_n_ceiling.g_c, floor_n_ceiling.b_c));
	}
	while (++y < HEIGHT_SCREEN)
	{
		i = -1;
		while (++i < WIDTH_SCREEN)
			my_mlx_pixel_put(data, i, y, create_trgb(0, floor_n_ceiling.r_f,
					floor_n_ceiling.g_f, floor_n_ceiling.b_f));
	}
}
