/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_initial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:00:42 by aaguiler          #+#    #+#             */
/*   Updated: 2022/12/31 19:00:43 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_list	*g_env_vars;

void	ft_get_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_add_one_env(env[i]);
		i++;
	}
}
