/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:29:08 by ngonzale          #+#    #+#             */
/*   Updated: 2022/05/17 17:02:56 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	i;
	size_t	n_len;

	n_len = ft_uilen(n);
	str = ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < n_len)
	{
		str[n_len - 1 - i] = '0' + n % 10;
		n /= 10;
		i++;
	}
	return (str);
}
