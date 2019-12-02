/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:30:05 by mroux             #+#    #+#             */
/*   Updated: 2019/11/04 15:30:07 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ret;

	if (lst == 0)
		return (0);
	if (!(ret = (t_list *)malloc(sizeof(t_list))))
	{
		ft_lstclear(&ret, del);
		return (0);
	}
	ret->content = (*f)(lst->content);
	new = ret;
	while (lst->next != 0)
	{
		lst = lst->next;
		if (!(new->next = (t_list *)malloc(sizeof(t_list))))
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		new = new->next;
		new->content = (*f)(lst->content);
	}
	new->next = 0;
	return (ret);
}
