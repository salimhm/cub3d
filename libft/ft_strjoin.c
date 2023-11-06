/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:05:06 by abouram           #+#    #+#             */
/*   Updated: 2023/10/24 20:40:08 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	p = (char *)malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1)
	{
		p[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		p[i] = *s2++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
