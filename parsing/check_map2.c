/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:17:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/15 20:15:29 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
    int count;
    int hold;

    count = 0;
    i = 0;
    hold = check_valid_path1(&essentials, i, &count);
    i = hold;
    j = 0;
    while (essentials.map[i])
    {
        ft_strlcpy(essentials.dummy_map[j], essentials.map[i], ft_strlen(essentials.map[i]) + 1);
        i++;
        j++;
    }
    i = 0;
    i++;
    j = i + 1;
    check_valid_path2(i, j, count, essentials);
    check_valid_path3(essentials, count);
    free2d(essentials.dummy_map);
}

void check_valid_path2(int i, int j, int count, t_parse_map essentials)
{
    int k;
    while (i < count)
    {
        if (!essentials.dummy_map[j])
            break;
        if (ft_strlen(essentials.dummy_map[i]) > ft_strlen(essentials.dummy_map[j]))
        {
            k = ft_strlen(essentials.dummy_map[j]) - 1;
            while (essentials.dummy_map[i][k])
            {
                if ((essentials.dummy_map[i][k] == '0' && essentials.dummy_map[i + 1][k] == '\0') || (essentials.dummy_map[i][k] == ' ' && essentials.dummy_map[i + 1][k] == '\0'))
                {
                    ft_putstr_fd("Error: invalid map!\n", 2);
                    free2d(essentials.map);
                    free2d(essentials.duplicates);
                    free2d(essentials.dummy_map);
                    exit(1);
                }
                k++;
            }
        }
        i++;
        j++;
    }
}

void check_valid_path3(t_parse_map essentials, int count)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (i < count)
    {
        k = 0;
        while (essentials.dummy_map[i][k])
        {
            if ((essentials.dummy_map[i][k] == '0' && essentials.dummy_map[i + 1][k] == ' '))
            {
                ft_putstr_fd("Error: invalid map!\n", 2);
                free2d(essentials.map);
                free2d(essentials.duplicates);
                free2d(essentials.dummy_map);
                exit(1);
            }
            k++;
        }
        i++;
    }
}

int check_valid_path1(t_parse_map *essentials, int i, int *count)
{
    int hold;
    int big_len;
    int j;

    while (check_elements_existance(essentials->duplicates[i]))
        i++;
    hold = i;
    big_len = ft_strlen(essentials->map[i]);
    while (essentials->map[i])
    {
        if (ft_strlen(essentials->map[i]) > big_len)
            big_len = ft_strlen(essentials->map[i]);
        i++;
        (*count)++;
    }
    i = hold;
    essentials->dummy_map = ft_calloc(sizeof(char *), ((*count) + 1));
    j = 0;
    while (essentials->map[i])
    {
        essentials->dummy_map[j] = ft_calloc(big_len + 1, 1);
        j++;
        i++;
    }
    return hold;
}