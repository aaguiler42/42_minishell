/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:57:46 by ngonzale          #+#    #+#             */
/*   Updated: 2022/04/21 00:34:45 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	ft_count_words(char *str, char c)
{
	int		n;

	n = 1;
	while (*str)
	{
		if (*str != c && (!*(str + 1) || *(str + 1) == c))
			n++;
		str++;
	}
	return (n);
}

static void	free_words(char **s, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	ft_add_words(char **words, char *start, char c)
{
	char	*next;
	size_t	i;

	i = 0;
	while (*start)
	{
		next = ft_strchr(start, c);
		if (!next || !*next)
		{
			words[i] = ft_substr(start, 0, ft_strlen(start));
			break ;
		}
		else
			words[i] = ft_substr(start, 0, next - start);
		if (!words[i])
		{
			free_words(words, i);
			return (0);
		}
		while (*next && *(next + 1) && *(next + 1) == c)
			next++;
		start = next + 1;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*start;

	words = ft_calloc(ft_count_words((char *) s, c), sizeof(char *));
	if (!words)
		return (0);
	start = (char *) s;
	while (*start && *start == c)
		start++;
	if (ft_add_words(words, start, c))
		return (words);
	else
		return (0);
}
