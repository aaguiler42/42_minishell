/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:16:53 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/10 17:09:13 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pipex_bonus.h"

extern t_all	*g_all;

int	ft_is_builtin(char *command)
{
	if (!ft_strncmp(command, "echo", 4))
		return (1);
	if (!ft_strncmp(command, "cd", 2))
		return (0);
	if (!ft_strncmp(command, "pwd", 3))
		return (1);
	if (!ft_strncmp(command, "export", 6))
		return (0);
	if (!ft_strncmp(command, "unset", 5))
		return (0);
	if (!ft_strncmp(command, "env", 3))
		return (1);
	if (!ft_strncmp(command, "exit", 4))
		return (0);
	return (-1);
}

void	ft_execute_builtin(t_command *command)
{
	if (!ft_strncmp(command->args[0], "echo", 4))
		ft_echo(command->args);
	if (!ft_strncmp(command->args[0], "cd", 2))
		ft_cd(command->args[1]);
	if (!ft_strncmp(command->args[0], "pwd", 3))
		ft_pwd(1);
	if (!ft_strncmp(command->args[0], "export", 6))
		ft_export(command->args[1]);
	if (!ft_strncmp(command->args[0], "unset", 5))
	{
		ft_unset(command->args[1]);
	}
	if (!ft_strncmp(command->args[0], "env", 3))
		ft_env();
	if (!ft_strncmp(command->args[0], "exit", 4))
		exit(1);
	// Memory leak
}

void	ft_exec_child(t_command *command, int ptc[2], int ctp[2], char **envp)
{
	close(ptc[1]);
	close(ctp[0]);
	if (command->fd_input > 1)
		dup2(command->fd_input, STDIN_FILENO);
	else
		dup2(ptc[0], STDIN_FILENO);
	if (command->fd_output > 1)
		dup2(command->fd_output, STDOUT_FILENO);
	else
		dup2(ctp[1], STDOUT_FILENO);
	if (ft_is_builtin(command->args[0]) == 1)
	{
		ft_execute_builtin(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (!command->path)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(command->args[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			command->path = ft_strdup("");
		}
		execve(command->path, command->args, envp);
	}
	exit(EXIT_FAILURE);
}

void	ft_exec_parent(t_command *command, int ptc[2], int ctp[2])
{
	char	*line;

	if (command->here_doc)
	{
		line = get_next_line(STDIN_FILENO);
		while (line && (ft_strncmp(command->here_doc, line, ft_strlen(line) - 1)
				|| ft_strlen(command->here_doc) != ft_strlen(line) - 1))
		{
			ft_putstr_fd(line, ptc[1]);
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		if (line)
			free(line);
	}
	close(ptc[1]);
	close(ptc[0]);
	close(ctp[1]);
}

int	ft_exec(t_command *command, char **envp)
{
	pid_t	pid;
	int		ptc[2];
	int		ctp[2];

	if (ft_is_builtin(command->args[0]) == 0)
	{
		ft_execute_builtin(command);
		return (-1);
	}
	if (pipe(ptc) == -1)
		return (-1);
	if (pipe(ctp) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_exec_child(command, ptc, ctp, envp);
	else
		ft_exec_parent(command, ptc, ctp);
	return (ctp[0]);
}
