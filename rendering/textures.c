/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:01:02 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/13 10:00:43 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(t_texture_data *textures, int x, int y, char direction)
{
	char			*dst;
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;

	if (direction == 'N')
		dst = textures->north.img_addr + (y * textures->north.line_length + x
				* (textures->north.bits_per_pixel / 8));
	else if (direction == 'S')
		dst = textures->south.img_addr + (y * textures->south.line_length + x
				* (textures->south.bits_per_pixel / 8));
	else if (direction == 'W')
		dst = textures->west.img_addr + (y * textures->west.line_length + x
				* (textures->west.bits_per_pixel / 8));
	else if (direction == 'E')
		dst = textures->east.img_addr + (y * textures->east.line_length + x
				* (textures->east.bits_per_pixel / 8));
	b = dst[0];
	g = dst[1];
	r = dst[2];
	t = dst[3];
	return (create_trgb(t, r, g, b));
}

void	get_offsets(t_data *data, t_texture_data *textures, int *x_offset,
		int *y_offset)
{
	if (data->h > data->v)
		*x_offset = (textures->north.img_width / WIDTH) * (data->verticaly
				- (int)data->verticaly / WIDTH) * WIDTH;
	else
		*x_offset = (textures->north.img_width / WIDTH) * (data->horizontalx
				- (int)data->horizontalx / WIDTH) * WIDTH;
}

void	render_textures(t_data *data, t_texture_data *textures, int *x_offset,
		int *y_offset)
{
	int	color;
	int	y;

	y = data->y_start;
	while (++data->y_start < data->y_end && data->y_start <= HEIGHT_SCREEN)
	{
		*y_offset = (data->y_start - y) * (textures->north.img_height
				/ data->point);
		if (data->y_start >= 0)
		{
			if (data->h < data->v && data->is_up)
				color = get_color(textures, *x_offset
						% (int)textures->north.img_width, *y_offset, 'N');
			if (data->h < data->v && data->is_down)
				color = get_color(textures, *x_offset
						% (int)textures->south.img_width, *y_offset, 'S');
			if (data->h > data->v && data->is_left)
				color = get_color(textures, *x_offset
						% (int)textures->west.img_width, *y_offset, 'W');
			else if (data->h > data->v && data->is_right)
				color = get_color(textures, *x_offset
						% (int)textures->east.img_width, *y_offset, 'E');
			my_mlx_pixel_put(data, data->i, data->y_start, color);
		}
	}
}
