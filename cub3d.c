/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:34 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/12 01:04:48 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(int keycode, void *par)
{
	t_data	*data;

	data = par;
	print_round(data);
	move_player(data, keycode);
	print_map(data);
	draw_fov_line(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (check_map(fd, av[1]))
			return (1);
	}
	else
	{
		ft_putstr_fd("Error: wrong number of args!\n", 2);
		return (1);
	}
}
