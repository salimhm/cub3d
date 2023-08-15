/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:17:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/15 01:50:38 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_map3(t_parse_map essentials)
{
    int i;
    int j;

    i = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    // free2d(essentials.duplicates);

    j = i + 1;
    while (essentials.map[i])
    {
        printf("%d\n", ft_strlen(essentials.map[i]));
        i++;
    }
}

// int check_player_duplicates2(t_parse_map essentials)
// {
//     int n;
//     int s;
//     int e;
//     int w;
// }

void check_player_duplicates(t_parse_map essentials)
{
    int *player;
    int i;
    int j;

    player = ft_calloc(sizeof(int), 4);
    i = 0;
    j = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    while (essentials.map[i])
    {
        j = 0;
        while (essentials.map[i][j])
        {
            if (essentials.map[i][j] == 'N')
                player[0]++;
            else if (essentials.map[i][j] == 'S')
                player[1]++;
            else if (essentials.map[i][j] == 'E')
                player[2]++;
            else if (essentials.map[i][j] == 'W')
                player[3]++;
            j++;
        }
        i++;
    }
    i = 0;
    j = 0;
    if (player[0] == 0 && player[1] == 0 && player[2] == 0 && player[3] == 0)
    {
        ft_putstr_fd("Error: one player required!\n", 2);
        free2d(essentials.map);
        free2d(essentials.duplicates);
        free(player);
        exit(1);
    }
    while (i < 4)
    {
        if (player[i] == 1)
        {
            while (j < 4)
            {
                if (player[j] != 0 && j != i)
                {
                    ft_putstr_fd("Error: only one player allowed!\n", 2);
                    free2d(essentials.map);
                    free2d(essentials.duplicates);
                    free(player);
                    exit(1);
                }
                j++;
            }
        }
        if (player[i] > 1)
        {
            ft_putstr_fd("Error: duplicate players detected!\n", 2);
            free2d(essentials.map);
            free2d(essentials.duplicates);
            free(player);
            exit(1);
        }
        i++;
    }
}

void check_valid_path(t_parse_map essentials)
{
    int i;
    int j;
    int k;
    int start;
    int lol;

    i = 0;
    while (check_elements_existance(essentials.duplicates[i]))
        i++;
    i++;
    j = i + 1;
    k = 0;
    while (essentials.map[i])
    {
        if (!essentials.map[j])
            break;
        if (ft_strlen(essentials.map[i]) > ft_strlen(essentials.map[j]))
        {
            start = ft_strlen(essentials.map[j]) - 1;
            k = start;
            lol = i;
            // printf("%s\n", essentials.map[lol]);
            while (essentials.map[lol][k])// && essentials.map[lol - 1][k]
            {
                printf("%d\n", k);
                if ((essentials.map[lol][k] == '0' && essentials.map[lol][k + 1] == '0') || (essentials.map[lol][k] == '0' && essentials.map[lol - 1][k] == '0' && essentials.map[lol][k + 1] == '0'))
                {
                    ft_putstr_fd("Error: invalid map!\n", 2);
                    printf("here %d | %c| %s\n", k, essentials.map[lol][k], essentials.map[lol]);
                    // printf("here lol %d\n", essentials.map[i][k]);
                    exit(1);
                }
                k++;
            }
        }
        i++;
        j++;
    }
}