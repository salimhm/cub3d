/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:12:15 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/11 04:21:29 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int get_color(t_texture_data *textures, int x, int y, char direction)
{
    char *dst;
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char t;

    if (direction == 'N')
        dst = textures->north.img_addr + (y * textures->north.line_length + x * (textures->north.bits_per_pixel / 8));
    else if (direction == 'S')
        dst = textures->south.img_addr + (y * textures->south.line_length + x * (textures->south.bits_per_pixel / 8));
    else if (direction == 'W')
        dst = textures->west.img_addr + (y * textures->west.line_length + x * (textures->west.bits_per_pixel / 8));
    else if (direction == 'E')
        dst = textures->east.img_addr + (y * textures->east.line_length + x * (textures->east.bits_per_pixel / 8));
    b = dst[0];
    g = dst[1];
    r = dst[2];
    t = dst[3];
    return (create_trgb(t, r, g, b));
}

void load_textures(t_texture_data *textures, t_data *data)
{
    int i;
    char *img_path;
    void *img;
    char *new_str;

    i = 0;
    while (i < 4)
    {
        new_str = ft_strtrim(data->call->elements[i], " \n");
        if (new_str[0] == 'N')
        {
            img_path = remove_spaces(data->call->elements[i]);
            if (img_path)
            {
                img = mlx_xpm_file_to_image(data->mlx, img_path, &textures->north.img_width, &textures->north.img_height);
                textures->north.img_addr = mlx_get_data_addr(img, &textures->north.bits_per_pixel, &textures->north.line_length,
                                                             &textures->north.endian);
            }
            free(img_path);
        }
        else if (new_str[0] == 'S')
        {
            img_path = remove_spaces(data->call->elements[i]);
            if (img_path)
            {
                img = mlx_xpm_file_to_image(data->mlx, img_path, &textures->south.img_width, &textures->south.img_height);
                textures->south.img_addr = mlx_get_data_addr(img, &textures->south.bits_per_pixel, &textures->south.line_length,
                                                             &textures->south.endian);
            }
            free(img_path);
        }
        else if (new_str[0] == 'W')
        {
            img_path = remove_spaces(data->call->elements[i]);
            if (img_path)
            {
                img = mlx_xpm_file_to_image(data->mlx, img_path, &textures->west.img_width, &textures->west.img_height);
                textures->west.img_addr = mlx_get_data_addr(img, &textures->west.bits_per_pixel, &textures->west.line_length,
                                                            &textures->west.endian);
            }
            free(img_path);
        }
        else if (new_str[0] == 'E')
        {
            img_path = remove_spaces(data->call->elements[i]);
            if (img_path)
            {
                img = mlx_xpm_file_to_image(data->mlx, img_path, &textures->east.img_width, &textures->east.img_height);
                textures->east.img_addr = mlx_get_data_addr(img, &textures->east.bits_per_pixel, &textures->east.line_length,
                                                            &textures->east.endian);
            }
            free(img_path);
        }
        free(new_str);
        i++;
    }
}