/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:31:05 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/02 23:36:53 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex_bonus.h"
#include <unistd.h>

void		ft_close_command_fd(void *content);
void		ft_free_command(void *content);
t_list		*ft_create_command_pipex(char *argv, int type, char **env_paths,
				char *limiter);
static void	ft_create_command_helper(t_list **command,
				t_command **content, int type, char *limiter);

t_list	*ft_create_command_pipex(char *argv, int type, char **env_paths,
	char *limiter)
{
	t_list		*command;
	t_command	*content;

	ft_create_command_helper(&command, &content, type, limiter);
	if (!command)
		return (NULL);
	if (type == TYPE_COMMAND)
	{
		content->args = ft_parse_command(argv);
		if (!content->args)
		{
			free(content);
			free(command);
			return (NULL);
		}
		content->path = ft_find_path(content->args[0], env_paths);
	}
	else
		content->path = argv;
	return (command);
}

void	ft_close_command_fd(void *content)
{
	t_command	*command;

	command = (t_command *) content;
	if (command->fd_input > 0)
		close(command->fd_input);
	if (command->fd_output > 0
		&& command->fd_output != STDOUT_FILENO)
		close(command->fd_output);
}

void	ft_free_command(void *content)
{
	t_command	*command;
	char		**args;

	command = (t_command *) content;
	ft_close_command_fd(content);
	if (command->type == TYPE_COMMAND)
	{
		if (command->path)
			free(command->path);
		args = command->args;
		if (args)
		{
			while (*args)
			{
				free(*args);
				args++;
			}
			free(command->args);
		}
	}
	free(command);
}

static void	ft_create_command_helper(t_list **command,
		t_command **content, int type, char *limiter)
{
	*command = NULL;
	*content = ft_calloc(1, sizeof(t_command));
	if (!*content)
		return ;
	*command = ft_lstnew((t_list *) *content);
	if (!*command)
		free(*content);
	(*content)->fd_input = STDIN_FILENO;
	(*content)->fd_output = STDOUT_FILENO;
	(*content)->args = NULL;
	if (type == TYPE_FILE_WRITE && limiter)
		type = TYPE_FILE_APPEND;
	else if (type == TYPE_FILE_READ && limiter)
		(*content)->here_doc = ft_strdup(limiter);
	(*content)->type = type;
}

void	ft_free_env_paths(char **env_paths)
{
	char	**ptr;

	ptr = env_paths;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(env_paths);
}
