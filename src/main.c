/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/20 18:07:19 by aaguiler         ###   ########.fr       */
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
		line = readline("[JUAN]~ ");
		if (!line)
			break ;
		add_history(line);
		commands = ft_get_commands(line);
		if (!commands)
			break ;
		// Aquí se ejecutan los comandos
	}
	ft_lstclear(&g_env_vars, free);
	clear_history();
}
