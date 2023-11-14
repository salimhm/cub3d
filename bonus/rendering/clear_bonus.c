/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 06:23:22 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/14 12:04:47 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	close_window(int keycode, t_data *data)
{
	(void)keycode;
	free_n_destroy(data);
	exit(0);
}

int	close_win(t_data *data)
{
	free_n_destroy(data);
	exit(0);
}

void	free_n_destroy(t_data *data)
{
	free2d(data->temp_essentials->map);
	free2d(data->temp_essentials->dummy_map);
	free2d(data->temp_essentials->duplicates);
	free2d(data->call->elements);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->call);
	free(data);
}
