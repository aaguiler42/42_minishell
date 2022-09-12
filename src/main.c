/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:53:20 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/12 20:33:51 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_table		table;
	char		*s;

	(void)argc;
	(void)argv;
	(void)env;
	s = readline("[JUAN]~ ");
	while (s)
	{
		ft_parse_line(s, &table);
		s = readline("[JUAN]~ ");
	}
}
