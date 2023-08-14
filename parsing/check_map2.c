/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:17:20 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/14 19:18:09 by shmimi           ###   ########.fr       */
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
    free2d(essentials.duplicates);

    j = i + 1;
    while (essentials.map[i])
    {
        printf("%d\n", ft_strlen(essentials.map[i]));
        i++;
    }
}