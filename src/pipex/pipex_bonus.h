/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:15:27 by narso             #+#    #+#             */
/*   Updated: 2023/01/04 18:19:57 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "../minishell.h"

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
char	**ft_get_env_paths(void);
char	*ft_find_path(char *command, char **env_paths);

#endif
