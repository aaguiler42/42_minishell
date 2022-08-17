/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2022/08/17 16:16:37 by aaguiler         ###   ########.fr       */
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
	while (line[start + i] != '|' && line[start + i] && !quotes)
	{
		if (line[start + i] == '\"' && quotes == 0)
			quotes = 2;
		else if (line[start + i] == '\"' && quotes == 2)
			quotes = 0;
		else if (line[start + i] == '\'' && quotes == 0)
			quotes = 1;
		else if (line[start + i] == '\'' && quotes == 1)
			quotes = 0;
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

	table->n_commands = ft_count_commands(line);
	//Controlar error comillas y dobles barras
	table->commands = (char **)malloc((table->n_commands + 1) * sizeof(char *));
	table->commands[table->n_commands] = NULL;
	start = 0;
	len = 0;
	i = 0;
	while (line[start + len])
	{
		start += len;
		//Controlar que pueda acabar con barra o empezar, trim al final y al principio
		if (line[start] == '|')
			start++;
		len = ft_get_command_len(line, start);
		printf("%d ", len);
		table->commands[i] = ft_substr(line, start, len);
		printf("\n");
		i++;
	}
	ft_print_table(table->commands);
	return (0);
}
