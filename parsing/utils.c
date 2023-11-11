/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:26:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/11 04:17:32 by shmimi           ###   ########.fr       */
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

void free2d(char **arg)
{
	int i;

	if (!arg)
		return;
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

char **get_elements(t_parse_map essentials, char *map)
{
	int i;
	int j;
	int fd;
	char **elements;
	char *line;
	char **temp;

	i = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;

	// printf("%d\n", i);
	elements = malloc(sizeof(char *) * 10 + 1);
	j = 0;
	fd = open(map, O_RDONLY);

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_split(line, ' ');
		if (temp[0] && essentials.duplicates[i] && ft_strncmp(essentials.duplicates[i], temp[0], ft_strlen(temp[0]) + 1) == 0)
		{
			elements[i] = ft_strdup(line);
			// printf("%s", elements[i]);
			i++;
		}
		free2d(temp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);

	// printf("%d\n", i);
	elements[i] = NULL;
	// i = 0;
	// while (elements[i])
	// {
	// 	printf("wwww %s", elements[i]);
	// 	i++;
	// }
	return elements;
}

char *remove_spaces(char *str)
{
	int i;
	int j;
	char *new_str;

	i = 0;
	j = 0;
	str = ft_strchr2(str, ' ');
	new_str = ft_calloc(ft_strlen(str), 1);
	while (str[i] == ' ')
		i++;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
	{
		while (str[i] != ' ')
			i++;
		str = ft_strchr2(str, ' ');
	}
	if (i == 0)
	{
		while (str[i])
		{
			if (str[i] == '\n' || str[i] == ' ')
				break;
			new_str[j] = str[i];
			i++;
			j++;
		}
		return new_str;
	}
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == ' ')
			break;
		new_str[j++] = str[i++];
	}
	return new_str;
}

int is_element_exist(t_parse_map *essentials)
{
	int i;

	i = 0;
	while (essentials->map[i])
	{
		// printf("%s\n", essentials->map[i]);
		i++;
	}
	return 0;
}