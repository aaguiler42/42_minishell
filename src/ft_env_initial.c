/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_initial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:00:42 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/10 16:45:58 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_all	*g_all;

int	ft_get_env(int argc, char **argv, char **env)
{
	int		i;

	(void)argc;
	(void)argv;
	i = 0;
	while (env[i])
	{
		if (!ft_add_one_env(env[i]))
			return (0);
		i++;
	}
	return (1);
}
