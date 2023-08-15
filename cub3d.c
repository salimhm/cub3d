/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:11:14 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/14 22:22:04 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int fd;
        fd = open(av[1], O_RDONLY);
        if (check_map(fd, av[1]))
            return 1;
    }
    else
    {
        ft_putstr_fd("Error: wrong number of args!\n", 2);
        return 1;
    }
}