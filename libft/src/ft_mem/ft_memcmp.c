/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:36:22 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 22:54:31 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	if (n == 0)
		return (0);
	s1_c = (unsigned char *) s1;
	s2_c = (unsigned char *) s2;
	i = 0;
	while (i < n - 1 && s1_c[i] == s2_c[i])
		i++;
	return (s1_c[i] - s2_c[i]);
}
