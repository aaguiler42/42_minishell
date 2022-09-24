/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:14:48 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/24 13:42:58 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_errors(char *line)
{
	int	quotes;
	int	n_commands;
	int	i;

	if (line[0] == '|' || line[ft_strlen(line) - 1] == '|')
		return (0);
	quotes = 0;
	n_commands = 1;
	i = 0;
	while (line[i])
	{
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

	bare_command = ft_strtrim_spaces(ft_substr(line, start, len));
	if (!bare_command)
		return (NULL);
	command = ft_calloc(sizeof(t_command *), 1);
	if (!command)
	{
		free(bare_command);
		return (NULL);
	}
	command->type = TYPE_COMMAND;
	command->command = bare_command;
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
			free(line);
			return (NULL);
		}
		ft_lstadd_back(&commands, list_aux);
	}
	free(line);
	ft_lstiter(commands, ft_substitute_env);
	return (commands);
}
