/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:49:53 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/15 17:56:10 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
