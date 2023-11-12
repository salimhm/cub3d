/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 06:23:22 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/11 06:45:08 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int close_window(int keycode, void *param)
{
    printf("Closing window\n");
    exit(0);
}

void close_win(t_data *data)
{
    mlx_hook(data->win, 17, 0, close_window, NULL);
}

void free_n_destroy(t_data *data, t_parse_map *essentials)
{
    free2d(essentials->map);
    free2d(essentials->dummy_map);
    free2d(essentials->duplicates);
    
    mlx_destroy_image(data->mlx, data->img);
}