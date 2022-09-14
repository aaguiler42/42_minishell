/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uilen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:43:42 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/17 16:45:30 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_uilen(unsigned int n)
{
	size_t	n_len;

	n_len = 0;
	if (n == 0)
		n_len = 1;
	while (n > 0)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}
