/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:49:53 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/25 19:52:39 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_list(void *list)
{
	t_command	*command;

	command = (t_command *)list;
	printf("%s\n", command->command);
}

void	print_env(void *list)
{
	char	*str;

	str = (char *)list;
	printf("%s\n", str);
}
