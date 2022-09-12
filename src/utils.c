/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/12 20:31:16 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (!quotes && i && line[i] == '|' && line[i - 1] == '|')
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
			break;
		i++;
	}
	return (i);
}

void	ft_print_table(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->n_commands)
	{
		printf("%s.\n", table->commands[i]);
		i++;
	}
}

int	ft_printf(char *msg){
	printf("%s", msg);
	return (0);
}

int	ft_parse_line(char *line, t_table *table)
{
	int	start;
	int	len;
	int	i;

	line = ft_strtrim(line, " ");
	if (line[0] == '|' || line[ft_strlen(line) - 1] == '|')
		return (ft_printf("SYNTAX ERROR\n"));
	table->n_commands = ft_count_commands(line);
	if (!table->n_commands)
		return (ft_printf("SYNTAX ERROR\n"));
	table->commands = (char **)ft_calloc((table->n_commands + 1), sizeof(char *));
	if (!table->commands)
		return (0);
	start = 0;
	len = 0;
	i = 0;
	while (line[start + len])
	{
		start += len;
		if (line[start] == '|')
			start++;
		len = ft_get_command_len(line, start);
		table->commands[i] = ft_substr(line, start, len);
		i++;
	}
	ft_print_table(table);
	free(line);
	return (0);
}
