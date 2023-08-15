/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:38:10 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/15 20:43:36 by shmimi           ###   ########.fr       */
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

// void check_empty_lines(t_parse_map essentials, char *file)
// {
//     // int i;
//     int fd;
//     (void)essentials;
//     fd = open(file, O_RDONLY);
    
//     char *test = get_next_line(fd);
//     printf("%s\n", test);
// }