/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:26:07 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/07 00:10:12 by shmimi           ###   ########.fr       */
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

	elements = malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	fd = open(map, O_RDONLY);

	while (check_elements_existance(essentials.duplicates[i]))
		i++;

	while (j < i)
	{
		line = get_next_line(fd);
		elements[j] = ft_strdup(line);
		// free(line);
		j++;
	}

	i = 0;
	while (elements[i])
	{
		printf("%s", elements[i]);
		i++;
	}
	return elements;
}

char *remove_spaces(char *str)
{
	int i;
	int j;
	char *new_str;

	i = 0;
	j = 0;
	str = ft_strchr(str, ' ');

	new_str = ft_calloc(ft_strlen(str) - 1, 1);
	while(str[i] == ' ')
		i++;
	while(str[i] != '\n' || str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	// free(str);
	
	
	return new_str;
}