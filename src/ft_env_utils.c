/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:59:43 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/10 16:46:38 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_all	*g_all;

int	ft_add_one_env(char *env)
{
	char	*aux;
	t_list	*list_aux;

	aux = ft_strdup(env);
	if (!aux)
	{
		ft_lstclear(&(g_all)->env_list, free);
		// TODO COMPROBAR CON EXPORT
		return (0);
	}
	list_aux = ft_lstnew(aux);
	if (!list_aux)
	{
		ft_lstclear(&(g_all)->env_list, free);
		free(aux);
		// TODO COMPROBAR CON EXPORT
		return (0);
	}
	ft_lstadd_back(&(g_all)->env_list, list_aux);
	return (1);
}

char	*ft_get_env_value(char *env)
{
	t_list	*env_vars;
	char	*content;
	int		len;

	len = 0;
	env_vars = (g_all)->env_list;
	while (env_vars)
	{
		content = ((char *)env_vars->content);
		if (!ft_strncmp(env_vars->content, env, ft_strlen(env))
			&& content[ft_strlen(env)] == '=')
		{
			len = ft_strlen(content) - ft_strlen(env) - 1;
			return (ft_substr(content, ft_strlen(env) + 1, len));
		}
		env_vars = env_vars->next;
	}
	return (NULL);
}
