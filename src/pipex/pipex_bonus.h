/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:27 by narso             #+#    #+#             */
/*   Updated: 2023/01/02 23:36:42 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"

# define TYPE_FILE_READ 0
# define TYPE_FILE_WRITE 1
# define TYPE_FILE_APPEND 2
# define TYPE_COMMAND 3

typedef struct s_command {
	char	*path;
	char	**args;
	int		type;
	int		fd_input;
	int		fd_output;
	char	*here_doc;
	char *command;
}		t_command;

// Checker
char	*ft_check_args(int argc, char **argv);

// Commands
t_list	*ft_get_commands_pipex(char **argv, int argc, char **env_paths,
			char *limiter);
void	ft_execute_command(t_list *lstcommand, char **envp);
t_list	*ft_create_command_pipex(char *argv, int type, char **env_paths,
			char *limiter);
void	ft_free_command(void *content);
void	ft_free_env_paths(char **env_paths);

// Parser
char	**ft_parse_command(char *arg);

// Exec
int		ft_exec(t_command *command, char **envp);

// Path
char	**ft_get_env_paths(char **envp);
char	*ft_find_path(char *command, char **env_paths);

#endif
