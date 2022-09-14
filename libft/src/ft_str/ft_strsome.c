/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:52:53 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/09 01:05:21 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strsome(char *str, int (*f)(size_t, char))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (f(i, str[i]))
			return (1);
		i++;
	}
	return (0);
}
