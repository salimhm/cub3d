/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:31:01 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/13 01:09:04 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	skip_newline(int fd, char **line)
{
	while (*line && ft_strncmp(*line, "\n", 2) == 0)
	{
		if (*line[0] == '1' || *line[0] == ' ')
			return ;
		free(*line);
		*line = get_next_line(fd);
	}
}

void	check_empty_lines2(t_parse_map *essentials, char *line, int fd)
{
	skip_newline(fd, &line);
	while (line)
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			while (line)
			{
				if (line && ft_strncmp(line, "\n", 2) == 0)
				{
					ft_putstr_fd("Error: \"\\n\" detected in between!\n", 2);
					free(line);
					free2d(essentials->map);
					free2d(essentials->duplicates);
					exit(1);
				}
				free(line);
				line = get_next_line(fd);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	check_empty_lines3(t_parse_map essentials, char **element, char **line,
		int fd)
{
	int	i;

	i = 0;
	while (i < get_num_lines(essentials))
	{
		element = ft_split(*line, ' ');
		if (check_elements_existance(element[0]))
		{
			free(*line);
			*line = get_next_line(fd);
		}
		i++;
		free2d(element);
	}
}

void	check_empty_lines(t_parse_map essentials, char *file)
{
	int		fd;
	char	*line;
	char	**element;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	check_empty_lines3(essentials, element, &line, fd);
	free(line);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error: map content missing!\n", 2);
		free2d(essentials.map);
		free2d(essentials.duplicates);
		exit(1);
	}
	check_empty_lines2(&essentials, line, fd);
}

void	rgb_check(char *rgbs, char **element, t_parse_map essentials)
{
	char	**rgb;
	int		i;
	int		count;

	rgb = ft_split(rgbs, ',');
	if (ft_strlen_2d(rgb) != 3)
	{
		ft_putstr_fd("Error: invalid rgb element\n", 2);
		free2d(rgb);
		free2d(essentials.map);
		free2d(element);
		exit(1);
	}
	rgb_check2(rgb, element, essentials);
	rgb_check3(rgb, &essentials, element);
	rgb_check4(rgbs, element, &essentials, rgb);
	free2d(rgb);
}
