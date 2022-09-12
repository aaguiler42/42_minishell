/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:55 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/12 19:44:14 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct s_command
{
	int		n_args;
	char	**args;
}	t_command;

typedef	struct s_table
{
	int			n_commands;
	char		**commands;

}	t_table;

int		ft_parse_line(char *line, t_table *table);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char *s1, char *set);
int		ft_strlen (char *s);
void	*ft_calloc(int count, int size);

#endif
