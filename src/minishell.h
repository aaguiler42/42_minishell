/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:55 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/20 15:32:17 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_table
{
	int			n_commands;
	char		**commands;

}	t_table;

//Utils
int		ft_parse_line(char *line, char **commands);
int		ft_count_commands(char *line);

//Free
char	**ft_free_line(char *line);

//Trim
char	*ft_strtrim_spaces(char *s);

//Print
void	ft_print_commands(char **commands);

//Env
void	ft_get_env(char **env);

#endif
