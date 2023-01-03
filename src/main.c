/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/04 00:01:54 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_list	*g_env_vars = NULL;

void	c_handler(int dummy)
{
	(void)dummy;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*ft_get_line(void)
{
	char	*line;

	line = readline("[JUAN]~ ");
	if (!line)
		return (NULL);
	add_history(line);
	// TODO: Hacer que no se añada al historial si es un comando vacío y heredoc tampoco
	line = ft_strtrim_spaces_quotes(line);
	if (!line)
		return (NULL);
	if (!ft_check_errors(line))
	{
		free(line);
		line = ft_strdup("Syntax error");
	}
	return (line);
}

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

// ft_unset(ft_strdup("TERM_PROGRAM"));
// ft_export(ft_strdup("PATH=hola"));
// ft_env();
// ft_pwd();
// ft_cd(ft_strdup("/"));
// atexit(ft_leaks);
int	main(int argc, char **argv, char **env)
{
	t_list	*commands;
	char	*line;

	(void)argc;
	(void)argv;
	ft_get_env(env);
	signal(SIGINT, c_handler);
	signal(SIGQUIT, c_handler);
	while (1)
	{
		line = ft_get_line();
		if (!line)
			break ;
		commands = ft_get_commands(line);
		if (!commands && line[0])
			break ;
		// ft_lstiter(commands, print_list);
		pipex(commands, env);
		// ft_lstclear(&commands, ft_free_list);
	}
	ft_lstclear(&g_env_vars, free);
	clear_history();
}
