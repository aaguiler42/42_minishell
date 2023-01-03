/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:16:53 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/04 00:00:27 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pipex_bonus.h"

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
	if (!command->path)
		command->path = ft_strdup("");
	execve(command->path, command->args, envp);
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
