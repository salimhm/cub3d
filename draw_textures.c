/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:12:15 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/07 00:10:39 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int get_color(t_texture_data *textures, int x, int y)
{
    char *dst;
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char t;

    dst = textures->img_addr + (y * textures->line_length + x * (textures->bits_per_pixel / 8));
    b = dst[0];
    g = dst[1];
    r = dst[2];
    t = dst[3];
    return (create_trgb(t, r, g, b));
}

void draw_textures(t_texture_data *textures, t_data *data)
{
    char *img_path = "./textures/6.xpm";
    void *img;
    if (img_path)
    {
        img = mlx_xpm_file_to_image(data->mlx, img_path, &textures->img_width, &textures->img_height);
        textures->img_addr = mlx_get_data_addr(img, &textures->bits_per_pixel, &textures->line_length,
                                               &textures->endian);
    }
}