/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:29:18 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/23 01:53:23 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_elements2(t_parse_map essentials)
{
    int i;
    char **element;

    i = 0;
    while (i < 6)
    {
        element = ft_split_origin(essentials.map[i], ' ');
        if (ft_strlen_2d(element) > 2)
        {
            ft_putstr_fd("Error: invalid element\n", 2);
            free2d(essentials.map);
            free2d(element);
            exit(1);
        }
        if (is_rgb(element[0]))
            rgb_check(element[1], element, essentials);
        i++;
        free2d(element);
    }
    return 0;
}

int check_elements_existance(char *element)
{
    char *elements[6];
    int i;

    elements[0] = "NO";
    elements[1] = "SO";
    elements[2] = "WE";
    elements[3] = "EA";
    elements[4] = "F";
    elements[5] = "C";
    i = 0;
    while (i < 6)
    {
        if (element && ft_strncmp(elements[i], element, ft_strlen(elements[i]) + 1) == 0)
            return 1;
        i++;
    }
    return 0;
}

void check_all_elements(t_parse_map essentials)
{
    char **element;
    int i;
    int j;

    i = 0;
    j = 0;
    while (essentials.map[i])
    {
        element = ft_split_origin(essentials.map[i], ' ');
        if (check_elements_existance(element[0]))
            j++;
        i++;
        free2d(element);
    }
    if (j != 6)
    {
        ft_putstr_fd("Error: one or more elements is missing\n", 2);
        free2d(essentials.map);
        exit(1);
    }
}

int check_elements(t_parse_map essentials)
{
    int i;
    char **element;
    int fd;

    check_all_elements(essentials);
    i = 0;
    while (i < 6)
    {
        element = ft_split_origin(essentials.map[i], ' ');
        if (ft_strlen_2d(element) != 2)
        {
            ft_putstr_fd("Error: invalid element\n", 2);
            free2d(essentials.map);
            free2d(element);
            exit(1);
        }
        if (is_coord(element[0]))
        {
            fd = open(element[1], O_RDONLY);
            if (fd < 0)
            {
                ft_putstr_fd("Error: invalid element texture\n", 2);
                free2d(essentials.map);
                free2d(element);
                close(fd);
                exit(1);
            }
            close(fd);
        }
        free2d(element);
        i++;
    }
    check_elements2(essentials);
    return 0;
}

void check_duplicates(t_parse_map *essentials)
{
    char **element;
    int i;
    int j;

    essentials->duplicates = malloc(sizeof(char *) * (16 + 1));
    i = 0;
    while (essentials->map[i])
    {
        element = ft_split_origin(essentials->map[i], ' ');
        if (check_elements_existance(element[0]))
            essentials->duplicates[i] = ft_strdup(element[0]);
        free2d(element);
        i++;
    }
    essentials->duplicates[6] = NULL;
    i = 1;
    j = 0;
    while (essentials->duplicates[i])
    {
        if (essentials->duplicates[i] && ft_strncmp(essentials->duplicates[i], essentials->duplicates[j], ft_strlen(essentials->duplicates[i]) + 1) == 0)
        {
            free2d(essentials->duplicates);
            free2d(essentials->map);
            ft_putstr_fd("Error: duplicate elements detected\n", 2);
            exit(1);
        }
        if (i == 5)
            j = 0;
        i++;
    }
}