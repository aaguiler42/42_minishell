/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:38:06 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/17 17:41:40 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	char	*str;
	size_t	i;
	size_t	n_len;
	size_t	base_len;

	base_len = ft_strlen(base);
	n_len = ft_ulllen_base(n, base_len);
	str = ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < n_len)
	{
		str[n_len - 1 - i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	return (str);
}
