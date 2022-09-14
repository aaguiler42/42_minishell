/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:17:53 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/14 21:34:33 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*ft_strtrim_and_free(char *s1, char *set)
{
	char	*s2;

	s2 = ft_strtrim(s1, set);
	free(s1);
	return (s2);
}

char	*ft_strtrim_spaces(char *line)
{
	line = ft_strtrim_and_free(line, " ");
	if (line)
		line = ft_strtrim_and_free(line, "\t");
	if (line)
		line = ft_strtrim_and_free(line, "\n");
	if (line)
		line = ft_strtrim_and_free(line, "\v");
	if (line)
		line = ft_strtrim_and_free(line, "\f");
	if (line)
		line = ft_strtrim_and_free(line, "\r");
	return (line);
}
