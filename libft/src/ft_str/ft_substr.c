/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:11:04 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 16:23:05 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (0);
		return (substr);
	}
	if (s_len - start < len)
		len = s_len;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}
