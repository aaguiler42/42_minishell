/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uilen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:59:08 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/17 16:59:50 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_uilen_base(unsigned int n, size_t base_len)
{
	size_t	n_len;

	n_len = 0;
	if (n == 0)
		n_len = 1;
	while (n > 0)
	{
		n /= base_len;
		n_len++;
	}
	return (n_len);
}
