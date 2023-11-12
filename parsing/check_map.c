/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:15:48 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/12 10:37:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_map_check(char c, t_parse_map essentials)
{
	if (c != ' ')
	{
		if (c != '1')
		{
			ft_putstr_fd("Error: invalid map!\n", 2);
			free2d(essentials.map);
			free2d(essentials.duplicates);
			exit(1);
		}
	}
	return (0);
}

int	check_corners(t_parse_map essentials)
{
	int	i;
	int	j;

	i = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	while (essentials.map[++i])
	{
		if (parse_map_check(essentials.map[i][0], essentials)
			|| parse_map_check(essentials.map[i][ft_strlen(essentials.map[i])
				- 1], essentials))
			return (1);
	}
	i = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	j = -1;
	while (essentials.map[++i])
	{
		while (essentials.map[i][++j] == ' ')
			if (parse_map_check(essentials.map[i][j], essentials))
				return (1);
		j = 0;
	}
	return (0);
}

int	check_first_n_last(t_parse_map essentials)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	while (essentials.map[i][j])
	{
		if (parse_map_check(essentials.map[i][j], essentials))
			return (1);
		j++;
	}
	i = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	while (essentials.map[i])
		i++;
	j = -1;
	while (essentials.map[i - 1][++j])
	{
		if (parse_map_check(essentials.map[i - 1][j], essentials))
			return (1);
	}
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;
	double	a;

	data = param;
	//
	data->call->retation_angle = (tan((float)300 / (float)(2 * WIDTH_SCREEN
					- x)) / WIDTH_SCREEN) * 1e5;
	// mlx_clear_window(data->mlx, data->win);
	print_round(data);
	draw_fov_line(data);
	print_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	// draw_player(data, data->call->new_x, data->call->new_y);
	return (0);
}

void	check_map2(int fd, char *file)
{
	t_data		*data;
	t_parse_map	essentials;
	char		*line;
	char		*buffer;
	int			i;

	data = ft_calloc(1, sizeof(t_data));
	data->call = ft_calloc(1, sizeof(t_map));
	line = get_next_line(fd);
	buffer = ft_strdup("");
	while (line)
	{
		if (!line)
			break ;
		buffer = ft_strjoin(buffer, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	essentials.map = ft_split(buffer, '\n');
	free(buffer);
	check_elements(essentials);
	check_duplicates(&essentials);
	data->call->elements = get_elements(essentials, file);
	check_empty_lines(essentials, file);
	check_first_n_last(essentials);
	check_corners(essentials);
	check_player_duplicates(essentials);
	check_weird_chars(essentials);
	check_valid_path(&essentials);
	// **************************************** AYOUB *********************************************
	data->call->map = essentials.dummy_map;
	i = 0;
	data->call->i = ft_strlen(data->call->map[0]);
	while (data->call->map[i])
	{
		if (data->call->i < ft_strlen(data->call->map[i]))
			data->call->i = ft_strlen(data->call->map[i]);
		i++;
	}
	data->call->j = i;
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
	// FREE
	// free2d(essentials.dummy_map);
	// free2d(essentials.duplicates);
	// free(data->call);
	// free(data);
}

int	check_map(int fd, char *file)
{
	char	*extension;

	extension = ft_strchr(file, '.');
	if (fd < 0)
	{
		ft_putstr_fd("Error: map not found!\n", 2);
		return (1);
	}
	if (!extension)
	{
		ft_putstr_fd("Error: \".cub\" extension needed\n", 2);
		return (1);
	}
	if (ft_strncmp(extension, "cub", 4))
	{
		ft_putstr_fd("Error: rename the extention to .cub\n", 2);
		return (1);
	}
	check_map2(fd, file);
	return (0);
}
