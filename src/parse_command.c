/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:54:51 by aaguiler          #+#    #+#             */
/*   Updated: 2022/08/23 18:16:11 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_n_args(char *cmd)
{
	int	n_args;
	int	i;

	n_args = 1;
	i = 0;
	while(cms[i])
	{
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
	command->n_args = ft_get_n_args(cmd);
	return (command);
}
