/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_fn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:19:07 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/04 18:34:07 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Chapuza para que funcione con el PATH y el strncmp
t_list	*ft_lstfind_fn(t_list *lst, void *data_ref, int (*cmp)())
{
	t_list	*l;

	l = lst;
	while (l && cmp(l->content, data_ref, 5))
		l = l->next;
	return (l);
}
