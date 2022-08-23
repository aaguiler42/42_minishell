/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2022/08/23 17:52:36 by aaguiler         ###   ########.fr       */
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

void	ft_print_table(char **table)
{
	int	i;

	i = 0;
	while(table[i])
	{
		printf("%s.\n", table[i]);
		i++;
	}
}

int	ft_parse_line(char *line, t_table *table)
{
	int	start;
	int	len;
	int	i;

	line = ft_strtrim(line, " ");
	if (line[0] == '|' || line[ft_strlen(line) - 1] == '|')
	{
		printf("SYNTAX ERROR\n");
		return (0);
	}
	table->n_commands = ft_count_commands(line);
	printf("NCOM %d\n", table->n_commands);
	if (!table->n_commands)
	{
		printf("SYNTAX ERROR\n");
		return (0);
	}
	table->commands = (char **)malloc((table->n_commands + 1) * sizeof(char *));
	if (!table->commands)
		return (0);
	table->commands[table->n_commands] = NULL;
	table->commands_args = (t_command **)malloc((table->n_commands + 1) * sizeof(t_command *));
	if (!table->commands_args)
		return (0);
	table->commands_args[table->n_commands] = NULL;
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
		table->commands_args[i] = ft_parse_command(table->commands[i]);
		i++;
	}
	ft_print_table(table->commands);
	free(line);
	return (0);
}
