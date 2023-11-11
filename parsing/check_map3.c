/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:38:10 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/11 00:48:29 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_allowed_chars(char component)
{
    char allowed_chars[8];
    int i;

    allowed_chars[0] = ' ';
    allowed_chars[1] = '0';
    allowed_chars[2] = '1';
    allowed_chars[3] = 'N';
    allowed_chars[4] = 'S';
    allowed_chars[5] = 'E';
    allowed_chars[6] = 'W';
    allowed_chars[7] = '\0';
    i = 0;
    while (allowed_chars[i])
    {
        if (allowed_chars[i] == component)
            return 1;
        i++;
    }
    return 0;
}

void check_weird_chars(t_parse_map essentials)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    while (essentials.map[i])
    {
        j = 0;
        // printf("%s\n", essentials.map[i]);
        while (essentials.map[i][j])
        {
            if (!check_allowed_chars(essentials.map[i][j]))
            {
                ft_putstr_fd("Error: weird char detected!\n", 2);
                printf("%c %d %s\n", essentials.map[i][j], j, essentials.map[i]);
                free2d(essentials.map);
                free2d(essentials.duplicates);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

int get_num_lines(t_parse_map essentials)
{
    int i;

    i = 0;
    while (essentials.map[i])
        i++;
    return i;
}

int allowed_player(char component)
{
    char allowed[5];
    int i;

    allowed[0] = 'N';
    allowed[1] = 'S';
    allowed[2] = 'E';
    allowed[3] = 'W';
    allowed[4] = '\0';

    i = 0;
    while (allowed[i])
    {
        if (component == 'N')
            return 1;
        if (component == 'S')
            return 2;
        if (component == 'E')
            return 3;
        if (component == 'W')
            return 4;
        i++;
    }
    return 0;
}

char get_starting_pos(t_parse_map essentials)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    while (essentials.map[i])
    {
        j = 0;
        while (essentials.map[i][j])
        {
            if (allowed_player(essentials.map[i][j]) == 1)
                return 'N';
            if (allowed_player(essentials.map[i][j]) == 2)
                return 'S';
            if (allowed_player(essentials.map[i][j]) == 3)
                return 'E';
            if (allowed_player(essentials.map[i][j]) == 4)
                return 'W';
            j++;
        }
        i++;
    }
    return 0;
}

void skip_newline(int fd, char *line)
{
    while (line && ft_strncmp(line, "\n", 2) == 0)
    {
        if (line[0] == '1' || line[0] == ' ')
            return;
        // printf("%s", line);
        // free(line);
        line = get_next_line(fd);
    }
}

void check_empty_lines(t_parse_map essentials, char *file)
{
    int i;
    int fd;
    char *line;
    char **element;

    (void)essentials;
    i = 0;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);

    // Skip All elements (Need to replace 25 by number of map lines)
    while (i < get_num_lines(essentials))
    {
        element = ft_split(line, ' ');
        if (check_elements_existance(element[0]))
        {
            free(line);
            line = get_next_line(fd);
        }
        i++;
        free2d(element);
    }
    free(line);
    line = get_next_line(fd);

    // Skip all first \n lines after elements (NO, SO...)
    while (line && ft_strncmp(line, "\n", 2) == 0)
    {
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    line = get_next_line(fd);
    if (!line)
    {
        ft_putstr_fd("Error: map content missing!\n", 2);
        free2d(essentials.map);
        free2d(essentials.duplicates);
        exit(1);
    }
    skip_newline(fd, line);
    while (line)
    {
        if (line[0] == '1' || line[0] == ' ')
        {
            while (line)
            {
                if (line && ft_strncmp(line, "\n", 2) == 0)
                {
                    ft_putstr_fd("Error: \"\\n\" detected in between!\n", 2);
                    free(line);
                    free2d(essentials.map);
                    free2d(essentials.duplicates);
                    exit(1);
                }
                free(line);
                line = get_next_line(fd);
            }
        }
        free(line);
        line = get_next_line(fd);
    }
    // printf("%s\n", get_next_line(fd));
}