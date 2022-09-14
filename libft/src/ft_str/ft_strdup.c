/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:17:39 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/20 15:14:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	size_t	i;
	char	*str;

	s_len = ft_strlen(s1);
	str = (char *) ft_calloc(s_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < s_len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
