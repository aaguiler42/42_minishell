/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:34:49 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 23:00:53 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;

	if (!dst && !src)
		return (dst);
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (n-- > 0)
		dst_c[n] = src_c[n];
	return (dst);
}
