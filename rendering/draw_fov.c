/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:04 by abouram           #+#    #+#             */
/*   Updated: 2023/11/13 08:39:08 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dis_hit_wall(t_data *data, int h, int v)
{
	while (data->incrmentx > 0 && ((int)data->incrmentx / WIDTH) < data->call->i
		&& data->incrmenty > 0 && ((int)data->incrmenty
			/ HEIGHT) < data->call->j)
	{
		if (data->call->map[((int)data->incrmenty)
				/ HEIGHT][(int)data->incrmentx / WIDTH] == '1')
		{
			if (h == 1)
				data->h_hit = 1;
			else if (v == 1)
				data->v_hit = 1;
			data->hitwallx = data->incrmentx;
			data->hitwally = data->incrmenty;
			break ;
		}
		else
		{
			data->incrmentx += data->xstep;
			data->incrmenty += data->ystep;
		}
	}
}

float	vertical(t_data *data, double h_x, double h_y)
{
	data_init(data);
	fix_r_angle(data);
	face_angel(data);
	if (data->is_right == 1)
		data->new_x = ((int)(data->x / WIDTH) + 1) * WIDTH;
	if (data->is_left == 1)
	{
		data->new_x = (int)(data->x / WIDTH) * WIDTH;
		data->new_x -= 0.0000000001;
	}
	data->new_y = data->y + (data->new_x - data->x) * tan(data->call->r_angle);
	data->xstep = HEIGHT;
	data->ystep = HEIGHT * tan(data->call->r_angle);
	if (data->is_left)
		data->xstep *= -1;
	if (data->is_up && data->ystep > 0)
		data->ystep *= -1;
	else if (data->is_down && data->ystep < 0)
		data->ystep *= -1;
	data->incrmentx = data->new_x;
	data->incrmenty = data->new_y;
	data->v_hit = 0;
	dis_hit_wall(data, 0, 1);
	return (close_dis(data, h_x, h_y));
}

float	horizontal_or_vertical(t_data *data)
{
	data_init(data);
	fix_r_angle(data);
	face_angel(data);
	if (data->is_down == 1)
		data->new_y = ((int)((data->y / HEIGHT)) + 1) * HEIGHT;
	else if (data->is_up == 1)
	{
		data->new_y = (int)(data->y / HEIGHT) * HEIGHT;
		data->new_y -= 0.0000000001;
	}
	data->new_x = data->x + (data->new_y - data->y) / tan(data->call->r_angle);
	data->ystep = HEIGHT;
	data->xstep = HEIGHT / tan(data->call->r_angle);
	if (data->is_up)
		data->ystep *= -1;
	if (data->is_left && data->xstep > 0)
		data->xstep *= -1;
	else if (data->is_right && data->xstep < 0)
		data->xstep *= -1;
	data->incrmentx = data->new_x;
	data->incrmenty = data->new_y;
	data->h_hit = 0;
	dis_hit_wall(data, 1, 0);
	data->dis = vertical(data, data->hitwallx, data->hitwally);
	return (data->dis);
}

void	check_textures(t_texture_data textures)
{
	if (textures.north.img_width == 32 || textures.north.img_width == 64)
	{
		if (textures.north.img_width == textures.south.img_width
			== textures.west.img_width == textures.south.img_width)
			return ;
	}
	else
	{
		ft_putstr_fd("Textures must have the same width and\
		height (32x32 or 64x)\n", 2);
		exit(1);
	}
	return ;
}

void	draw_fov_line(t_data *data)
{
	t_texture_data	textures;
	int				x_offset;
	int				y_offset;

	load_textures(&textures, data);
	check_textures(textures);
	data->i = 0;
	data->j = 0;
	data->fov = ((HEIGHT / 2) / (tan(M_PI / 6)));
	data->call->r_angle = data->call->retation_angle - (M_PI / 6);
	while (data->i < WIDTH_SCREEN)
	{
		data->call->r_angle += ((2 * M_PI / 6) / (WIDTH_SCREEN));
		data->dis_hit_wall = horizontal_or_vertical(data)
			* cos(data->call->r_angle - data->call->retation_angle);
		data->point = (HEIGHT_SCREEN / data->dis_hit_wall) * data->fov;
		data->y_start = (HEIGHT_SCREEN / 2) - (data->point / 2);
		data->y_end = data->y_start + data->point;
		get_offsets(data, &textures, &x_offset, &y_offset);
		render_textures(data, &textures, &x_offset, &y_offset);
		data->i++;
	}
	print_map(data);
	print_rays(data);
}
