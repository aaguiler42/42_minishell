/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:30 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/20 22:17:24 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1_len;
	size_t	start;
	size_t	end;

	s1_len = ft_strlen(s1);
	start = 0;
	while (start < s1_len)
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	end = s1_len - 1;
	while (ft_strchr(set, s1[end]))
		end--;
	end++;
	str = ft_substr(s1, start, end - start);
	return (str);
}
