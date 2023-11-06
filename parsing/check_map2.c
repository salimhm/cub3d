/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:17:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/10/24 20:41:46 by shmimi           ###   ########.fr       */
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
    free(player);
}

void check_valid_path(t_parse_map *essentials)
{
    int i;
    int j;
    int count;
    int hold;
    char starting_pos;

    starting_pos = get_starting_pos(*essentials);
    count = 0;
    i = 0;
    hold = check_valid_path1(essentials, i, &count);
    i = hold;
    j = 0;
    while (essentials->map[i])
    {
        ft_strlcpy(essentials->dummy_map[j], essentials->map[i], ft_strlen(essentials->map[i]) + 1);
        i++;
        j++;
    }
    i = 0;
    i++;
    j = i + 1;
    check_valid_path2(i, j, count, *essentials, starting_pos);
    free2d(essentials->map);
}

void check_valid_path2(int i, int j, int count, t_parse_map essentials, char starting_pos)
{
    int k;
    int m;

    while (i < count)
    {
        if (!essentials.dummy_map[j])
            break;
        if (ft_strlen(essentials.dummy_map[i]) >= ft_strlen(essentials.dummy_map[j]))
        {
            k = ft_strlen(essentials.dummy_map[i]) - 1;
            m = 0;
            while (m < k)
            {
                if ((essentials.dummy_map[i][m] == '0' || essentials.dummy_map[i][m] == starting_pos) && (essentials.dummy_map[i - 1][m] == '\0' || essentials.dummy_map[i + 1][m] == '\0' || essentials.dummy_map[i + 1][m] == ' ' || essentials.dummy_map[i][m - 1] == ' ' || essentials.dummy_map[i][m + 1] == ' ' || essentials.dummy_map[i - 1][m] == ' '))
                {
                    ft_putstr_fd("Error: invalid maps!\n", 2);
                    printf("|%c| %d %d\n", essentials.dummy_map[i][m], i, m);
                    free2d(essentials.map);
                    free2d(essentials.duplicates);
                    free2d(essentials.dummy_map);
                    exit(1);
                }
                m++;
            }
        }
        i++;
        j++;
    }
}


void check_valid_path3(t_parse_map essentials, int count, char starting_pos)
{
    int i;
    int k;

    i = 0;
    k = 0;
    // (void)starting_pos;
    while (i < count)
    {
        k = 0;
        while (essentials.dummy_map[i][k])
        {
            if (((essentials.dummy_map[i][k] == '0' || essentials.dummy_map[i][k] == starting_pos) && (essentials.dummy_map[i + 1][k] == ' ' || essentials.dummy_map[i - 1][k] == ' ')))
            {
                ft_putstr_fd("Error: invalid map!\n", 2);
                printf("|%c| %d %d\n", essentials.dummy_map[i][k], i, k);
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