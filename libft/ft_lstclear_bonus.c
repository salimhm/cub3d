/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:07:56 by abouram           #+#    #+#             */
/*   Updated: 2022/10/22 00:30:32 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (!lst || !del)
		return ;
	b = *lst;
	a = b;
	while (a)
	{
		b = b->next;
		del(a->content);
		free(a);
		a = b;
	}
	*lst = NULL;
}
