/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:26:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/13 20:34:09 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_strlen_2d(char **str2d)
{
    int i;

    i = 0;
    while (str2d[i])
        i++;
    return i;
}

void	free2d(char **arg)
{
	int	i;

	if (!arg)
		return ;
	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
	arg = NULL;
}
