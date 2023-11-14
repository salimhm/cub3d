/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:50:25 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/14 20:17:28 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_duplicates4(t_parse_map *essentials)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (essentials->duplicates[i])
	{
		while (essentials->duplicates[j])
		{
			if (ft_strncmp(essentials->duplicates[i], essentials->duplicates[j],
					ft_strlen(essentials->duplicates[i]) + 1) == 0)
			{
				ft_putstr_fd("Error: duplicate elements detected!\n", 2);
				free2d(essentials->duplicates);
				free2d(essentials->map);
				free2d(essentials->dummy_map);
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	check_elements_order(essentials);
}

void	check_elements_order(t_parse_map *essentials)
{
	if (ft_strncmp(essentials->duplicates[0], "NO", 3) == 0
		&& ft_strncmp(essentials->duplicates[1], "SO", 3) == 0
		&& ft_strncmp(essentials->duplicates[2], "WE", 3) == 0
		&& ft_strncmp(essentials->duplicates[3], "EA", 3) == 0
		&& ft_strncmp(essentials->duplicates[4], "F", 2) == 0
		&& ft_strncmp(essentials->duplicates[5], "C", 2) == 0)
		return ;
	else
	{
		ft_putstr_fd("Error: elements not ordered correctly!\n", 2);
		free2d(essentials->duplicates);
		free2d(essentials->map);
		free2d(essentials->dummy_map);
		exit(1);
	}
}

int	get_color_check(t_texture_data *textures, int x, int y)
{
	if (y == 64 || x == 64 || x < 0 || y < 0)
		return (0);
	if (x < 0 || x > textures->north.img_width || y < 0
		|| y > textures->north.img_height)
		return (0);
	if (x < 0 || x > textures->south.img_width || y < 0
		|| y > textures->south.img_height)
		return (0);
	if (x < 0 || x > textures->west.img_width || y < 0
		|| y > textures->west.img_height)
		return (0);
	if (x < 0 || x > textures->east.img_width || y < 0
		|| y > textures->east.img_height)
		return (0);
	return (1);
}
