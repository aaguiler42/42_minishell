/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:06 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/19 21:31:10 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

extern t_list	*g_env_vars;

int	ft_get_env(char **env)
{
	int		i;
	char	*aux;
	t_list	*list_aux;

	i = 0;
	while (env[i])
	{
		aux = ft_strdup(env[i]);
		if (!aux)
			//Free list
		list_aux = ft_lstnew(aux);
		if (!list_aux)
		{
			//Liberar lista
			free(aux);
		}
		ft_lstadd_back(&g_env_vars, list_aux);
		printf("%s\n", env[i++]);
	}
	return (0);
}
