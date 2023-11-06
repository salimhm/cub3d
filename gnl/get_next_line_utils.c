/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:33:24 by shmimi            #+#    #+#             */
/*   Updated: 2023/08/12 12:12:41 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strdup(char *s1)
// {
// 	size_t	i;
// 	char	*ptr;
// 	int		s_len;

// 	if (!s1)
// 		return (0);
// 	s_len = ft_strlen(s1);
// 	ptr = malloc(s_len + 1);
// 	i = 0;
// 	if (ptr == 0)
// 		return (0);
// 	while (s1[i] != '\0')
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (0);
	j = 0;
	while (j < s1_len)
	{
		new_str[j] = s1[j];
		j++;
	}
	while (i < s2_len)
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}
