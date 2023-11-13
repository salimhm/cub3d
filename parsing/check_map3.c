/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:38:10 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/13 01:08:06 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_allowed_chars(char component)
{
	char	allowed_chars[8];
	int		i;

	allowed_chars[0] = ' ';
	allowed_chars[1] = '0';
	allowed_chars[2] = '1';
	allowed_chars[3] = 'N';
	allowed_chars[4] = 'S';
	allowed_chars[5] = 'E';
	allowed_chars[6] = 'W';
	allowed_chars[7] = '\0';
	i = 0;
	while (allowed_chars[i])
	{
		if (allowed_chars[i] == component)
			return (1);
		i++;
	}
	return (0);
}

void	check_weird_chars(t_parse_map essentials)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	while (essentials.map[i])
	{
		j = 0;
		while (essentials.map[i][j])
		{
			if (!check_allowed_chars(essentials.map[i][j]))
			{
				ft_putstr_fd("Error: weird char detected!\n", 2);
				printf("%c %d %s\n", essentials.map[i][j], j,
					essentials.map[i]);
				free2d(essentials.map);
				free2d(essentials.duplicates);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	get_num_lines(t_parse_map essentials)
{
	int	i;

	i = 0;
	while (essentials.map[i])
		i++;
	return (i);
}

int	allowed_player(char component)
{
	char	allowed[5];
	int		i;

	allowed[0] = 'N';
	allowed[1] = 'S';
	allowed[2] = 'E';
	allowed[3] = 'W';
	allowed[4] = '\0';
	i = 0;
	while (allowed[i])
	{
		if (component == 'N')
			return (1);
		if (component == 'S')
			return (2);
		if (component == 'E')
			return (3);
		if (component == 'W')
			return (4);
		i++;
	}
	return (0);
}

char	get_starting_pos(t_parse_map essentials)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check_elements_existance(essentials.duplicates[i]))
		i++;
	while (essentials.map[i])
	{
		j = 0;
		while (essentials.map[i][j])
		{
			if (allowed_player(essentials.map[i][j]) == 1)
				return ('N');
			if (allowed_player(essentials.map[i][j]) == 2)
				return ('S');
			if (allowed_player(essentials.map[i][j]) == 3)
				return ('E');
			if (allowed_player(essentials.map[i][j]) == 4)
				return ('W');
			j++;
		}
		i++;
	}
	return (0);
}
