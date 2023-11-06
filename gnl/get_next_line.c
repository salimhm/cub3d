/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:37:55 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/12 11:58:47 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readd(int fd)
{
	char	*buff;
	char	*rest;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	rest = ft_strdup("");
	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		rest = ft_strjoin(rest, buff);
		if (ft_strchr(rest, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (rest);
}

char	*find_line(char *re, int i, int j)
{
	char	*nw_line;

	nw_line = NULL;
	if (!ft_strchr(re, '\n') && ft_strlen(re) > 0)
		return (re);
	while (re[i])
	{
		if (re[i] == '\n')
		{
			nw_line = malloc(i + 2);
			if (!nw_line)
				return (0);
			while (j <= i)
			{
				nw_line[j] = re[j];
				j++;
			}
			nw_line[j] = '\0';
			break ;
		}
		i++;
	}
	free(re);
	return (nw_line);
}

char	*remaining(char *readd, int i, int j)
{
	char	*remaining_chars;
	int		tmp;

	remaining_chars = NULL;
	if (readd && (!ft_strchr(readd, '\n') || ft_strlen(ft_strchr(readd,
					'\n')) <= 1))
		return (remaining_chars);
	while (readd[i])
	{
		if (readd[i] == '\n')
		{
			i++;
			tmp = ft_strlen(readd) - i;
			remaining_chars = malloc(tmp + 1);
			if (!remaining_chars)
				return (0);
			while (j < tmp)
				remaining_chars[j++] = readd[i++];
			remaining_chars[j] = '\0';
			break ;
		}
		i++;
	}
	return (remaining_chars);
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	static char	*remaining_chars;
	char		*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	j = 0;
	if (read(fd, NULL, 0) == -1)
	{
		if (remaining_chars)
		{
			free(remaining_chars);
			remaining_chars = NULL;
		}
		return (NULL);
	}
	text = readd(fd);
	line = ft_strjoin(remaining_chars, text);
	free(text);
	remaining_chars = remaining(line, i, j);
	line = find_line(line, i, j);
	return (line);
}

// #include <stdlib.h>
// int main(int ac , char **av)
// {
//     int i = 0;
//     int fd = open("t.txt", O_RDONLY);
//     while (atoi(av[1]) > i)
//     {
//         printf("\nLINE %d : %s", i, get_next_line(fd));
//         i++;
//     }
//     return (0);
// }

// int main()
// {
//     int fd = open("t.txt", O_RDONLY);
//     // get_next_line(fd);
//     printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // // printf("%s", get_next_line(fd));
//     // // printf("%s", get_next_line(fd));
//     // // printf("%s", get_next_line(fd));
//     // // printf("%s", get_next_line(fd));
//     // // printf("%s", get_next_line(fd));

//     return (0);
// }