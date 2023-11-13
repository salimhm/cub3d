/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:12:15 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/13 06:12:26 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north_texture(t_texture_data *textures, t_data *data, char *new_str)
{
	char	*img_path;
	void	*img;

	if (new_str[0] == 'N')
	{
		img_path = remove_spaces(new_str);
		if (img_path)
		{
			img = mlx_xpm_file_to_image(data->mlx, img_path,
					&textures->north.img_width, &textures->north.img_height);
			if (!img)
			{
				exit(1);
			}
			textures->north.img_addr = mlx_get_data_addr(img,
					&textures->north.bits_per_pixel,
					&textures->north.line_length,
					&textures->north.endian);
		}
		free(img_path);
	}
}

void	south_texture(t_texture_data *textures, t_data *data, char *new_str)
{
	char	*img_path;
	void	*img;

	if (new_str[0] == 'S')
	{
		img_path = remove_spaces(new_str);
		if (img_path)
		{
			img = mlx_xpm_file_to_image(data->mlx, img_path,
					&textures->south.img_width, &textures->south.img_height);
			if (!img)
			{
				exit(1);
			}
			textures->south.img_addr = mlx_get_data_addr(img,
					&textures->south.bits_per_pixel,
					&textures->south.line_length,
					&textures->south.endian);
		}
		free(img_path);
	}
}

void	west_texture(t_texture_data *textures, t_data *data, char *new_str)
{
	char	*img_path;
	void	*img;

	if (new_str[0] == 'W')
	{
		img_path = remove_spaces(new_str);
		if (img_path)
		{
			img = mlx_xpm_file_to_image(data->mlx, img_path,
					&textures->west.img_width, &textures->west.img_height);
			if (!img)
			{
				exit(1);
			}
			textures->west.img_addr = mlx_get_data_addr(img,
					&textures->west.bits_per_pixel,
					&textures->west.line_length,
					&textures->west.endian);
		}
		free(img_path);
	}
}

void	east_texture(t_texture_data *textures, t_data *data, char *new_str)
{
	char	*img_path;
	void	*img;

	if (new_str[0] == 'E')
	{
		img_path = remove_spaces(new_str);
		if (img_path)
		{
			img = mlx_xpm_file_to_image(data->mlx, img_path,
					&textures->east.img_width, &textures->east.img_height);
			if (!img)
			{
				exit(1);
			}
			textures->east.img_addr = mlx_get_data_addr(img,
					&textures->east.bits_per_pixel,
					&textures->east.line_length,
					&textures->east.endian);
		}
		free(img_path);
	}
}

void	load_textures(t_texture_data *textures, t_data *data)
{
	int		i;
	char	*img_path;
	void	*img;
	char	*new_str;

	i = 0;
	while (i < 4)
	{
		new_str = ft_strtrim(data->call->elements[i], " \n");
		north_texture(textures, data, new_str);
		south_texture(textures, data, new_str);
		west_texture(textures, data, new_str);
		east_texture(textures, data, new_str);
		free(new_str);
		i++;
	}
}
