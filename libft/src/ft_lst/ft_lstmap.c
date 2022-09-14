/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:42:53 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 22:52:59 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*ft_create_el(void *content, void *(*f)(void *))
{
	t_list	*new_el;

	new_el = (t_list *) ft_calloc(1, sizeof(t_list));
	if (!new_el)
		return (0);
	new_el->next = 0;
	new_el->content = f(content);
	if (!(new_el->content))
	{
		free(new_el);
		return (0);
	}
	return (new_el);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*curr;

	new_lst = ft_create_el(lst->content, f);
	if (!new_lst)
		return (0);
	curr = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		curr->next = ft_create_el(lst->content, f);
		if (!curr->next)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		curr = curr->next;
	}
	return (new_lst);
}
