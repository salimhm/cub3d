/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:27:29 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/13 01:21:42 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_duplicates2(t_parse_map *essentials, int i, int j)
{
	if (essentials->duplicates[i] && ft_strncmp(essentials->duplicates[i],
			essentials->duplicates[j], ft_strlen(essentials->duplicates[i])
			+ 1) == 0)
	{
		free2d(essentials->duplicates);
		free2d(essentials->map);
		ft_putstr_fd("Error: duplicate elements detected\n", 2);
		exit(1);
	}
}

void	check_duplicates(t_parse_map *essentials)
{
	char	**element;
	int		i;
	int		j;

	essentials->duplicates = malloc(sizeof(char *) * (16 + 1));
	i = -1;
	while (essentials->map[++i])
	{
		element = ft_split(essentials->map[i], ' ');
		if (check_elements_existance(element[0]))
			essentials->duplicates[i] = ft_strdup(element[0]);
		free2d(element);
	}
	essentials->duplicates[6] = NULL;
	i = 0;
	j = 0;
	while (essentials->duplicates[++i])
	{
		check_duplicates2(essentials, i, j);
		if (i == 5)
			j = 0;
	}
}

void	check_player_duplicates2(t_parse_map *essentials, int *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check_elements_existance(essentials->duplicates[i]))
		i++;
	while (essentials->map[i])
	{
		j = 0;
		while (essentials->map[i][j])
		{
			if (essentials->map[i][j] == 'N')
				player[0]++;
			else if (essentials->map[i][j] == 'S')
				player[1]++;
			else if (essentials->map[i][j] == 'E')
				player[2]++;
			else if (essentials->map[i][j] == 'W')
				player[3]++;
			j++;
		}
		i++;
	}
}

void	check_duplicates3(t_parse_map *essentials, int *player, int i, int j)
{
	if (player[i] == 1)
	{
		while (j < 4)
		{
			if (player[j] != 0 && j != i)
			{
				ft_putstr_fd("Error: only one player allowed!\n", 2);
				free2d(essentials->map);
				free2d(essentials->duplicates);
				free(player);
				exit(1);
			}
			j++;
		}
	}
	if (player[i] > 1)
	{
		ft_putstr_fd("Error: duplicate players detected!\n", 2);
		free2d(essentials->map);
		free2d(essentials->duplicates);
		free(player);
		exit(1);
	}
}

void	check_player_duplicates(t_parse_map essentials)
{
	int	*player;
	int	i;
	int	j;

	player = ft_calloc(sizeof(int), 4);
	check_player_duplicates2(&essentials, player);
	i = 0;
	j = 0;
	if (player[0] == 0 && player[1] == 0 && player[2] == 0 && player[3] == 0)
	{
		ft_putstr_fd("Error: one player required!\n", 2);
		free2d(essentials.map);
		free2d(essentials.duplicates);
		free(player);
		exit(1);
	}
	while (i < 4)
	{
		check_duplicates3(&essentials, player, i, j);
		i++;
	}
	free(player);
}
