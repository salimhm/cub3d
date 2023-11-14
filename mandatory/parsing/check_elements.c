/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:29:18 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/14 12:07:47 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_elements2(t_parse_map essentials)
{
	int		i;
	char	**element;

	i = 0;
	while (i < 6)
	{
		element = ft_split(essentials.map[i], ' ');
		if (ft_strlen_2d(element) > 2)
		{
			ft_putstr_fd("Error: invalid element\n", 2);
			free2d(essentials.map);
			free2d(element);
			exit(1);
		}
		if (is_rgb(element[0]))
			rgb_check(element[1], element, essentials);
		i++;
		free2d(element);
	}
	return (0);
}

int	check_elements_existance(char *element)
{
	char	*elements[6];
	int		i;

	elements[0] = "NO";
	elements[1] = "SO";
	elements[2] = "WE";
	elements[3] = "EA";
	elements[4] = "F";
	elements[5] = "C";
	i = 0;
	while (i < 6)
	{
		if (element && ft_strncmp(elements[i], element, ft_strlen(elements[i])
				+ 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_all_elements(t_parse_map essentials)
{
	char	**element;
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (essentials.map[++i])
	{
		element = ft_split(essentials.map[i], ' ');
		if (check_elements_existance(element[0]))
			j++;
		else if (element[0] && !check_elements_existance(element[0])
			&& element[0][0] != '1')
		{
			printf("Error: invalid map!\n");
			exit(1);
		}
		free2d(element);
	}
	if (j != 6)
	{
		ft_putstr_fd("Error: one or more elements is missing\n", 2);
		free2d(essentials.map);
		exit(1);
	}
}

void	check_if_coord(char **element, int fd, t_parse_map *essentials)
{
	if (is_coord(element[0]))
	{
		fd = open(element[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error: invalid element texture\n", 2);
			free2d(essentials->map);
			free2d(element);
			close(fd);
			exit(1);
		}
		close(fd);
	}
}

int	check_elements(t_parse_map essentials)
{
	int		i;
	char	**element;
	int		fd;

	fd = 0;
	check_all_elements(essentials);
	i = -1;
	while (++i < 6)
	{
		element = ft_split(essentials.map[i], ' ');
		if (ft_strlen_2d(element) != 2)
		{
			ft_putstr_fd("Error: invalid element\n", 2);
			free2d(essentials.map);
			free2d(element);
			exit(1);
		}
		check_if_coord(element, fd, &essentials);
		free2d(element);
	}
	check_elements2(essentials);
	return (0);
}
