/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:25:24 by abouram           #+#    #+#             */
/*   Updated: 2022/10/22 00:05:44 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*a;

	if (!lst)
		return ;
	a = lst;
	while (a)
	{
		f(a->content);
		a = a->next;
	}
}
