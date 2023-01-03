/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:55 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/02 23:36:40 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define TYPE_FILE_READ 0
# define TYPE_FILE_WRITE 1
# define TYPE_COMMAND 3

typedef struct s_command
{
	int			type;
	char		*command;
}	t_command;

void pipex (t_list *commands, char **envp);

//Utils
int		ft_count_commands(char *line);
int		ft_get_command_len(char *line, int start);
t_list	*ft_get_commands(char *line);
int		ft_check_errors(char *line);

//Free
char	**ft_free_line(char *line);
void	ft_free_list(void *content);

//Trim
char	*ft_strtrim_spaces_quotes(char *s);

//Print
void	print_list(void *list);
void	print_env(void *list);

//Env
void	ft_get_env(char **env);
char	*ft_get_env_value(char *env);
void	ft_substitute_env(void *list_elem);
void	ft_add_one_env(char *env);

//Builtins
void	ft_env(void);
void	ft_export(char *env);
void	ft_unset(char *env_name);
void	ft_pwd(void);
void	ft_cd(char *path);
void	ft_echo(int argc, char **argv);

#endif
