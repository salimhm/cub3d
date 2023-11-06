/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:31:10 by abouram           #+#    #+#             */
/*   Updated: 2022/10/22 00:16:24 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;
	t_list	*l;

	a = lst;
	if (!lst)
		return (NULL);
	l = NULL;
	while (a != NULL)
	{
		b = ft_lstnew((f)(a->content));
		ft_lstadd_back(&l, b);
		if (!b->content)
			ft_lstclear(&l, del);
		a = a->next;
	}
	return (l);
}
