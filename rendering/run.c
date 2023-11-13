/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:25 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/13 08:39:18 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_pointers(t_parse_map *essentials)
{
	essentials->map = NULL;
	essentials->dummy_map = NULL;
	essentials->duplicates = NULL;
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;
	double	a;

	data = param;
	data->call->retation_angle = (tan((float)300 / (float)(2 * WIDTH_SCREEN
					- x)) / WIDTH_SCREEN) * 1e5;
	print_round(data);
	draw_fov_line(data);
	print_map(data);
	print_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	run(t_data *data, t_parse_map *essentials)
{
	data->temp_essentials = essentials;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH_SCREEN, HEIGHT_SCREEN, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	print_map(data);
	data->call->new_x = data->call->py;
	data->call->new_y = data->call->px;
	draw_player(data, data->call->new_y, data->call->new_x);
	print_round(data);
	draw_fov_line(data);
	mlx_hook(data->win, 6, 0L, mouse_move, data);
	mlx_hook(data->win, 2, 0, move, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	close_win(data);
	mlx_loop(data->mlx);
}

void	init_game(t_parse_map *essentials, char *file)
{
	t_data	*data;
	int		i;

	i = 0;
	data = ft_calloc(1, sizeof(t_data));
	data->call = ft_calloc(1, sizeof(t_map));
	data->call->elements = get_elements(*essentials, file);
	check_player_duplicates(*essentials);
	check_weird_chars(*essentials);
	check_valid_path(essentials);
	data->call->map = essentials->dummy_map;
	i = 0;
	data->call->i = ft_strlen(data->call->map[0]);
	while (data->call->map[i])
	{
		if (data->call->i < ft_strlen(data->call->map[i]))
			data->call->i = ft_strlen(data->call->map[i]);
		i++;
	}
	data->call->j = i;
	run(data, essentials);
}
