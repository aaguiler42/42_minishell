/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:55 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 23:04:18 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	dst_length = 0;
	src_length = 0;
	while (dst[dst_length])
		dst_length++;
	while (src[src_length])
		src_length++;
	if (dstsize == 0 || dstsize <= dst_length)
		return (src_length + dstsize);
	while (src[i] && i < dstsize - dst_length - 1)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = 0;
	return (dst_length + src_length);
}
