/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:15:48 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/23 05:56:13 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int parse_map_check(char c, t_parse_map essentials)
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
    return 0;
}

int check_corners(t_parse_map essentials)
{
    int i;
    int j;

    i = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    while (essentials.map[i])
    {
        if (parse_map_check(essentials.map[i][0], essentials) || parse_map_check(essentials.map[i][ft_strlen(essentials.map[i]) - 1], essentials))
            return 1;
        i++;
    }
    i = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    j = 0;
    while (essentials.map[i])
    {
        while (essentials.map[i][j] == ' ')
            j++;
        if (parse_map_check(essentials.map[i][j], essentials))
            return 1;
        i++;
        j = 0;
    }
    return 0;
}

int check_first_n_last(t_parse_map essentials)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    while (essentials.map[i][j])
    {
        if (parse_map_check(essentials.map[i][j], essentials))
            return 1;
        j++;
    }
    i = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    while (essentials.map[i])
        i++;

    j = 0;
    while (essentials.map[i - 1][j])
    {
        if (parse_map_check(essentials.map[i - 1][j], essentials))
            return 1;
        j++;
    }
    return 0;
}

void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

void check_map2(int fd, char *file)
{
    t_parse_map essentials;
    char *line;
    char *buffer;

    line = get_next_line(fd);
    buffer = ft_strdup("");
    while (line)
    {
        if (!line)
            break;
        buffer = ft_strjoin(buffer, line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    essentials.map = ft_split_origin(buffer, '\n');
    free(buffer);
    check_elements(essentials);
    check_duplicates(&essentials);
    // (void)file;
    check_empty_lines(essentials, file);
    check_first_n_last(essentials);
    check_corners(essentials);
    check_player_duplicates(essentials);
    check_weird_chars(essentials);
    check_valid_path(essentials);
    // print_map(essentials.map);
}

int check_map(int fd, char *file)
{
    char *extension;

    extension = ft_strchr(file, '.');
    if (fd < 0)
    {
        ft_putstr_fd("Error: map not found!\n", 2);
        return 1;
    }
    if (!extension)
    {
        ft_putstr_fd("Error: \".cub\" extension needed\n", 2);
        return 1;
    }
    if (ft_strncmp(extension, "cub", 4))
    {
        ft_putstr_fd("Error: rename the extention to .cub\n", 2);
        return 1;
    }
    check_map2(fd, file);
    return 0;
}
