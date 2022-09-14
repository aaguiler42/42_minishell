/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/14 20:51:38 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

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

int	main(int argc, char **argv, char **env)
{
	char	**commands;
	char	*line;

	(void)argc;
	(void)argv;
	(void)env;
	line = readline("[JUAN]~ ");
	while (line)
	{
		commands = ft_get_commands(line);
		if (!commands)
			return (1);
		ft_print_commands(commands);
		// Aquí se ejecutan los comandos
		free(commands);
		line = readline("[JUAN]~ ");
		if (!line)
			return (1);
	}
}
