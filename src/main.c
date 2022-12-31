/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/25 12:06:20 by aaguiler         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	t_list	*commands;
	char	*line;

	atexit(ft_leaks);
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
		ft_lstiter(commands, print_list);
		// Aquí se ejecutan los comandos
		ft_lstclear(&commands, ft_free_list);
	}
	ft_lstclear(&g_env_vars, free);
	clear_history();
}
