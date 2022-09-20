/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:06 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/20 15:37:30 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

extern t_list	*g_env_vars;

void	ft_get_env(char **env)
{
	int		i;
	char	*aux;
	t_list	*list_aux;

	i = 0;
	while (env[i])
	{
		aux = ft_strdup(env[i]);
		if (!aux)
		{
			ft_lstclear(&g_env_vars, free);
			exit(1);
		}
		list_aux = ft_lstnew(aux);
		if (!list_aux)
		{
			ft_lstclear(&g_env_vars, free);
			free(aux);
			exit(1);
		}
		ft_lstadd_back(&g_env_vars, list_aux);
		i++;
	}
}
