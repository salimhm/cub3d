/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:26:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/14 12:01:22 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_2d(char **str2d)
{
	int	i;

	i = 0;
	while (str2d[i])
		i++;
	return (i);
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

void	get_elements2(t_parse_map *essentials, char *line, char **elements,
		int fd)
{
	int		i;
	char	**temp;

	i = 0;
	while (line)
	{
		temp = ft_split(line, ' ');
		if (temp[0] && essentials->duplicates[i]
			&& ft_strncmp(essentials->duplicates[i], temp[0], ft_strlen(temp[0])
				+ 1) == 0)
		{
			elements[i] = ft_strdup(line);
			i++;
		}
		free2d(temp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	elements[i] = NULL;
}

char	**get_elements(t_parse_map essentials, char *map)
{
	int		i;
	int		fd;
	char	**elements;
	char	*line;

	i = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	elements = malloc(sizeof(char *) * 10 + 1);
	fd = open(map, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	get_elements2(&essentials, line, elements, fd);
	return (elements);
}

char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	str = ft_strchr2(str, ' ');
	new_str = ft_strtrim(str, " ");
	return (new_str);
}
