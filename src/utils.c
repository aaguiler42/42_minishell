/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/07 17:40:46 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO Mejorar mucho
int	ft_check_errors(char *line)
{
	int	quotes;
	int	i;

	if (line[0] == '|' || line[ft_strlen(line) - 1] == '|')
		return (0);
	quotes = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == '\\' || line[i] == ';') && !quotes)
			return (0);
		if (line[i] == quotes)
			quotes = 0;
		else if (!quotes && ft_strchr("\"'", line[i]))
			quotes = line[i];
		if (!quotes && line[i] == '|' && line[i + 1] && line[i + 1] == '|')
			return (0);
		i++;
	}
	if (quotes)
		return (0);
	return (1);
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

t_list	*ft_create_command(char *line, int start, int len)
{
	t_command	*command;
	char		*bare_command;
	t_list		*list_aux;

	bare_command = ft_strtrim_spaces_quotes(ft_substr(line, start, len));
	if (!bare_command)
		return (NULL);
	command = ft_calloc(sizeof(t_command *), 1);
	if (!command)
	{
		free(bare_command);
		return (NULL);
	}
	char **bare_args = malloc(sizeof(char *) * 1);
	char *bare_here_doc = malloc(sizeof(char) * 1);
	command->type = TYPE_COMMAND;
	command->command = bare_command;
	command->path = NULL;
	command->args = bare_args;
	command->fd_input = 0;
	command->fd_output = 0;
	command->here_doc = bare_here_doc;
	list_aux = ft_lstnew(command);
	if (!list_aux)
	{
		free(command);
		free(bare_command);
		return (NULL);
	}
	return (list_aux);
}

t_list	*ft_get_commands(char *line)
{
	t_list		*commands;
	t_list		*list_aux;
	int			start;
	int			len;

	start = 0;
	len = 0;
	commands = NULL;
	while (line[start + len])
	{
		start += len;
		if (line[start] == '|')
			start++;
		len = ft_get_command_len(line, start);
		list_aux = ft_create_command(line, start, len);
		if (!list_aux)
		{
			ft_lstclear(&commands, ft_free_list);
			return (free(line), NULL);
		}
		ft_lstadd_back(&commands, list_aux);
	}
	ft_lstiter(commands, ft_substitute_env);
	return (free(line), commands);
}
