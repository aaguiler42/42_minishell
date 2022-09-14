/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:38:41 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 01:44:28 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	long	nb;
	int		n_len;

	n_len = 0;
	nb = n;
	if (nb <= 0)
		n_len = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;
	int		n_len;
	int		negative;

	n_len = ft_numlen(n);
	str = ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (0);
	nb = n;
	negative = 0;
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
		negative = 1;
	}
	i = -1;
	while (++i < n_len - negative)
	{
		str[n_len - 1 - i] = '0' + nb % 10;
		nb /= 10;
	}
	return (str);
}
