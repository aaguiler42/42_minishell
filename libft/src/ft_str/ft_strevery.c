/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:01:22 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/09 01:05:35 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strevery(char *str, int (*f)(size_t, char))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!f(i, str[i]))
			return (0);
		i++;
	}
	return (1);
}
