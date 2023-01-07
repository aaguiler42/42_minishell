/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nonzale <ngonzale@student.42malaga.comm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:21:13 by narso             #+#    #+#             */
/*   Updated: 2023/01/03 23:31:18 by ngonzle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

extern t_list	*g_env_vars;

void	ft_execute_commands(t_list *commands, char **envp)
{
	t_list		*cur_command;

	cur_command = commands;
	while (cur_command)
	{
		ft_execute_command(cur_command, envp);
		cur_command = cur_command->next;
	}
}


void pipex (t_list *commands, char **envp)
{
	t_list	*lst;
	t_list	*tmp;
	t_list	*tmp2;
	char		**env_vars;

	env_vars = ft_get_env_paths();
	tmp = commands;
	lst = ft_create_command_pipex((((t_command *)(tmp->content))->command), 3, env_vars, NULL);
	tmp = tmp->next;
	while (tmp)
	{
		tmp2 = ft_create_command_pipex((((t_command *)(tmp->content))->command), 3, env_vars, NULL);
		ft_lstadd_back(&lst, tmp2);
		tmp = tmp->next;
	}
	ft_execute_commands(lst, envp);
}
