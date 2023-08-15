/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:30:45 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/14 22:38:56 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_coord(char *coord)
{
    char *coords[4];
    int i;

    coords[0] = "NO";
    coords[1] = "SO";
    coords[2] = "WE";
    coords[3] = "EA";
    i = 0;
    while (i < 4)
    {
        if (ft_strncmp(coords[i], coord, ft_strlen(coords[i] + 1)) == 0)
            return 1;
        i++;
    }
    return 0;
}

int is_rgb(char *rgb)
{
    char *rgbs[2];
    int i;

    rgbs[0] = "F";
    rgbs[1] = "C";
    i = 0;
    while (i < 2)
    {
        if (ft_strncmp(rgbs[i], rgb, ft_strlen(rgbs[i]) + 1) == 0)
            return 1;
        i++;
    }
    return 0;
}

void rgb_check2(char **rgb, char **element, t_parse_map essentials)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (rgb[i])
    {
        j = 0;
        while (rgb[i][j])
        {
            if (!ft_isdigit(rgb[i][j]))
            {
                ft_putstr_fd("Error: invalid rgb character\n", 2);
                free2d(rgb);
                free2d(essentials.map);
                free2d(element);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void rgb_check(char *rgbs, char **element, t_parse_map essentials)
{
    char **rgb;
    int i;

    rgb = ft_split_origin(rgbs, ',');
    if (ft_strlen_2d(rgb) != 3)
    {
        ft_putstr_fd("Error: invalid rgb element\n", 2);
        free2d(rgb);
        free2d(essentials.map);
        free2d(element);
        exit(1);
    }
    rgb_check2(rgb, element, essentials);
    i = 0;
    while (rgb[i])
    {
        if (ft_atoi_origin(rgb[i]) < 0 || ft_atoi_origin(rgb[i]) > 255)
        {
            ft_putstr_fd("Error: invalid rgb color\n", 2);
            free2d(rgb);
            free2d(essentials.map);
            free2d(element);
            exit(1);
        }
        i++;
    }
    free2d(rgb);
}
