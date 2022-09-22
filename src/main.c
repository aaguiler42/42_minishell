/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/22 17:42:33 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	line = ft_strtrim_spaces(line);
	if (!line)
		return (NULL);
	if (!ft_check_errors(line))
	{
		free(line);
		return (NULL);	
	}
	return (line);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*commands;
	char	*line;

	(void)argc;
	(void)argv;
	ft_get_env(env);
	signal(SIGINT, c_handler);
	while (1)
	{
		line = ft_get_line();
		if (!line)
			break ;
		commands = ft_get_commands(line);
		if (!commands && line[0])
			break ;
		// Aquí se ejecutan los comandos
	}
	ft_lstclear(&g_env_vars, free);
	clear_history();
}
