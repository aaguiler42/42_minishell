/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:50:10 by aaguiler          #+#    #+#             */
/*   Updated: 2022/08/17 16:10:29 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sbstr;
	unsigned int	i;

	if (start >= ft_strlen(s))
	{
		sbstr = malloc(1 * sizeof(char));
		if (!sbstr)
			return (0);
		sbstr[0] = 0;
		return (sbstr);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sbstr = malloc((len + 1) * sizeof(char));
	if (!sbstr)
		return (0);
	sbstr[len] = 0;
	i = 0;
	while (s[start + i] && i < len)
	{
		sbstr[i] = s[start + i];
		i++;
	}
	return (sbstr);
}

