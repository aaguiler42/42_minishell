/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:26:56 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/22 18:38:11 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_free_line(char *line)
{
	free(line);
	return (NULL);
}

void	ft_free_list(void *content)
{
	t_command	*command;

	command = (t_command *)content;
	free(command->command);
	free(command);
}
