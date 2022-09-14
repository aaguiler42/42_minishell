/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/14 18:55:10 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_line(char *s)
{
	free(s);
	return(1);
}

int	ft_free_table(t_table *table)
{
	free(table->commands);
	return(1);
}

int	main(int argc, char **argv, char **env)
{
	t_table		table;
	char		*line;

	(void)argc;
	(void)argv;
	(void)env;
	line = readline("[JUAN]~ ");
	while (line)
	{
		if(!ft_parse_line(line, &table))
			return (ft_free_line(line));
		line = readline("[JUAN]~ ");
		if (!line)
			return(ft_free_table(&table));
	}
}
