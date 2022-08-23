/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:54:51 by aaguiler          #+#    #+#             */
/*   Updated: 2022/08/23 18:37:37 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_n_args(char *cmd)
{
	int	quotes;
	int	n_args;
	int	i;

	quotes = 0;
	n_args = 1;
	i = 0;
	while(cmd[i])
	{
		if (cmd[i] == '\"' && quotes == 0)
			quotes = 2;
		else if (cmd[i] == '\"' && quotes == 2)
			quotes = 0;
		else if (cmd[i] == '\'' && quotes == 0)
			quotes = 1;
		else if (cmd[i] == '\'' && quotes == 1)
			quotes = 0;
		else if (cmd[i] == ' ' && !quotes)
			n_args++;
		while (cmd[i] && cmd[i] == ' ')
			i++;
		i++;
	}
	return (n_args);
}

t_command	*ft_parse_command(char *cmd)
{
	t_command	*command;

	command = malloc(sizeof(t_command*) * 1);
	if (!command)
		return (0);
	cmd = ft_strtrim(cmd, " ");
	command->n_args = ft_get_n_args(cmd);
	return (command);
}
