/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/10 17:05:02 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_all	*g_all = NULL;

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

int	main(int argc, char **argv, char **env)
{
	char	*line;

	// atexit(ft_leaks);
	if (!ft_init(argc, argv, env))
		return (1);
	signal(SIGINT, c_handler);
	signal(SIGQUIT, c_handler);
	while (1)
	{
		line = ft_get_line();
		if (!line)
			break ;
		if (!ft_get_commands(line) && line[0])
			break ;
		// ft_lstiter((g_all)->commands, print_list);
		if ((g_all)->commands)
			pipex((g_all)->commands);
		// ft_lstclear(&commands, ft_free_list);
	}
	// ft_lstclear(&(g_all)->env_list, free);
	clear_history();
}
