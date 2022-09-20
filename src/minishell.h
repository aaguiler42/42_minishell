/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:55 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/20 17:01:07 by aaguiler         ###   ########.fr       */
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
# define TYPE_COMMAND 2

typedef struct s_command
{
	int			type;
	char		*command;
}	t_command;

//Utils
int		ft_count_commands(char *line);
int		ft_get_command_len(char *line, int start);
t_list	*ft_get_commands(char *line);

//Free
char	**ft_free_line(char *line);

//Trim
char	*ft_strtrim_spaces(char *s);

//Print
void	ft_print_commands(char **commands);

//Env
void	ft_get_env(char **env);

#endif
