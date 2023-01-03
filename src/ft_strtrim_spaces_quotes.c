/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_spaces_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:17:53 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/02 13:27:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtrim_and_free(char *s1, char *set)
{
	char	*s2;

	s2 = ft_strtrim(s1, set);
	free(s1);
	return (s2);
}

char	*ft_eliminate_quotes_start(char *line)
{
	char	*command_aux;

	if (line[0] == line[1] && (line[0] == '\'' || line[0] == '\"'))
	{
		command_aux = ft_substr(line, 2, ft_strlen(line) - 2);
		free(line);
		if (!command_aux)
			return (NULL);
		return (ft_eliminate_quotes_start(command_aux));
	}
	return (line);
}

char	*ft_eliminate_quotes_final(char *line)
{
	int		len;
	char	*command_aux;

	len = ft_strlen(line) - 1;
	if (line[len] == line[len - 1] && (line[len] == '\'' || line[len] == '\"'))
	{
		command_aux = ft_substr(line, 0, ft_strlen(line) - 2);
		free(line);
		if (!command_aux)
			return (NULL);
		return (ft_eliminate_quotes_final(command_aux));
	}
	return (line);
}

char	*ft_strtrim_spaces_quotes(char *line)
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
	if (line)
		line = ft_eliminate_quotes_start(line);
	if (line)
		line = ft_eliminate_quotes_final(line);
	//TODO: check with echo ""
	return (line);
}
