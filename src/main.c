/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/19 20:58:58 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_list	*g_env_vars = NULL;

char	**ft_get_commands(char *line)
{
	char	**commands;
	int		n_commands;

	line = ft_strtrim_spaces(line);
	if (!line)
		return (NULL);
	n_commands = ft_count_commands(line);
	if (!n_commands)
		return (ft_free_line(line));
	commands = ft_calloc((n_commands + 1), sizeof(char *));
	if (!commands)
		return (ft_free_line(line));
	if (!ft_parse_line(line, commands))
		return (ft_free_line(line));
	return (commands);
}

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
	char	**commands;
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
		add_history (line);
		commands = ft_get_commands(line);
		if (!commands)
			return (1);
		ft_print_commands(commands);
		// Aquí se ejecutan los comandos
		free(commands);
	}
	clear_history();
}
