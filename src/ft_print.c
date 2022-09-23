/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:49:53 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/23 17:19:20 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ft_print_commands(char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		ft_printf("%s.\n", commands[i]);
		i++;
	}
}

void	print_list(void *list)
{
	t_command	*command;

	command = (t_command *)list;
	printf("%s\n", command->command);
}
