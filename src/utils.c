/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/14 21:26:08 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

/*
if (line[i] == '\"' && quotes == 0)
	quotes = 2;
else if (line[i] == '\"' && quotes == 2)
	quotes = 0;
else if (line[i] == '\'' && quotes == 0)
	quotes = 1;
else if (line[i] == '\'' && quotes == 1)
	quotes = 0;
else if (line[i] == '|' && !quotes)
	n_commands++;
*/

int	ft_count_commands(char *line)
{
	int	quotes;
	int	n_commands;
	int	i;

	quotes = 0;
	n_commands = 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == quotes)
		 	quotes = 0;
		 else if (!quotes && ft_strchr("\"'", line[i]))
		 	quotes = line[i];
		else if (!quotes && line[i] == '|')
			n_commands++;
		if (line[0] == '|' || (!quotes && line[i] == '|' && (!line[i + 1]
				|| (line[i + 1] && line[i + 1] == '|'))))
			return (0);
		i++;
	}
	if (quotes)
		return (0);
	return (n_commands);
}

int	ft_get_command_len(char *line, int start)
{
	int	quotes;
	int	i;

	quotes = 0;
	i = 0;
	while (line[start + i])
	{
		if (line[start + i] == '\"' && quotes == 0)
			quotes = 2;
		else if (line[start + i] == '\"' && quotes == 2)
			quotes = 0;
		else if (line[start + i] == '\'' && quotes == 0)
			quotes = 1;
		else if (line[start + i] == '\'' && quotes == 1)
			quotes = 0;
		if (line[start + i] == '|' && !quotes)
			break ;
		i++;
	}
	return (i);
}

int	ft_parse_line(char *line, char **commands)
{
	int	start;
	int	len;
	int	i;

	start = 0;
	len = 0;
	i = 0;
	while (line[start + len])
	{
		start += len;
		if (line[start] == '|')
			start++;
		len = ft_get_command_len(line, start);
		commands[i++] = ft_substr(line, start, len);
		//Liberar commandos si falla algun malloc
	}
	free(line);	
	return (1);
}
