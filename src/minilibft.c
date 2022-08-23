/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:50:10 by aaguiler          #+#    #+#             */
/*   Updated: 2022/08/23 16:23:20 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen (char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sbstr;
	int		i;

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

char	*ft_strchr (char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p && *p != (char)c)
		p++;
	if (*p == (char)c)
		return (p);
	return (0);
}

int	ft_get_first(char *s1, char *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

int	ft_get_last(char *s1, char *set)
{
	int	k;
	int	i;

	i = 0;
	k = ft_strlen(s1);
	while (s1[--k] && ft_strchr(set, s1[k]))
		i++;
	return (i);
}

void	ft_asign_value(char *s1, char *s2, int j, int len)
{
	int	i;

	i = 0;
	while (j < len)
		s2[i++] = s1[j++];
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		len;
	char	*s2;

	i = ft_get_first(s1, set);
	if (i == ft_strlen(s1))
	{
		s2 = malloc(2 * sizeof(char));
		if (!s2)
			return (0);
		s2[0] = 0;
		s2[1] = 0;
		return (s2);
	}
	len = ft_strlen(s1) - (i + ft_get_last(s1, set));
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	s2[len] = 0;
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	len += i;
	ft_asign_value (s1, s2, i, len);
	free(s1);
	return (s2);
}
