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

/*
int	main(int argc, char **argv, char **envp)
{
	t_list		*commands;
	char		**env_paths;
	char		*limiter;

	limiter = ft_check_args(argc, argv);
	env_paths = ft_get_env_paths(envp);
	if (!env_paths)
		return (EXIT_FAILURE);
	if (limiter)
		commands = ft_get_commands(argv + 2, argc - 2, env_paths, limiter);
	else
		commands = ft_get_commands(argv + 1, argc - 1, env_paths, NULL);
	ft_execute_commands(commands, envp);
	ft_free_env_paths(env_paths);
	ft_lstclear(&commands, ft_free_command);
	return (EXIT_SUCCESS);
}
*/

char **env_vars;

void *change_command(void *content) {
	t_command *command;
	t_list		*new_commands;

	command = (t_command *)content;
	new_commands = ft_create_command_pipex(command->command, command->type, env_vars, NULL);
	return ((void *)new_commands);
}

void pipex (t_list *commands, char **envp)
{
	// t_list *new_commands;
	t_list *lst;
	// t_list *lst_2;
	t_list *tmp;
	t_list *tmp2;
	// t_command *tmp2_content;

(void)commands;
	env_vars = ft_get_env_paths(envp);
	// ft_lstiter(commands, print_list);
	// new_commands = ft_lstmap(commands, change_command, ft_free_command);
	tmp = commands;
	lst = ft_create_command_pipex((((t_command *)(tmp->content))->command), 3, env_vars, NULL);
	tmp = tmp->next;
	while (tmp)
	{
		ft_printf("command: %s\n", (((t_command *)(tmp->content))->command));
		tmp2 = ft_create_command_pipex((((t_command *)(tmp->content))->command), 3, env_vars, NULL);
		ft_lstadd_back(&lst, tmp2);
		tmp = tmp->next;
	}
	// lst = ft_create_command_pipex("ls", 3, env_vars, NULL);
	// lst_2 = ft_create_command_pipex("wc", 3, env_vars, NULL);
	// ft_lstclear(&commands, ft_free_command);
	// printf("%p\n", new_commands->content);
	// printf("TT |%s|\n", ((t_command *)(lst->content))->command);
	// printf("pa ti mi cola\n");
	// ft_lstiter(new_commands, print_list);
	// ft_lstadd_back(&lst, lst_2);
	ft_execute_commands(lst, envp);
}
