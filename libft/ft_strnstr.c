/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:23:38 by abouram           #+#    #+#             */
/*   Updated: 2022/10/22 18:20:20 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len - (ft_strlen(needle) - 1))
	{
		if (ft_strncmp(needle, &haystack[i], ft_strlen(needle)) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
