/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:06 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/22 20:09:03 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_have_env(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '$' && command[i + 1] && !ft_isspace(command[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_env_value(char *env)
{
	t_list	*env_vars;
	char	*content;
	int		len;

	len = 0;
	env_vars = g_env_vars;
	while (env_vars)
	{
		content = ((char *)env_vars->content);
		if (!ft_strncmp(env_vars->content, env, ft_strlen(env))
			&& content[ft_strlen(env)] == '=')
		{
			len = ft_strlen(content) - ft_strlen(env) - 1;
			return (ft_substr(content, ft_strlen(env) + 1, len));//
		}
		env_vars = env_vars->next;
	}
	return (NULL);
}

char	*ft_get_command_after_env(char *command)
{
	int		i;
	int		len;
	char	*env_name;

	i = 0;
	while (command[i])
	{
		len = 0;
		if (command[i] == '$')
		{
			while (command[i + len + 1] && !ft_isspace(command[i + len + 1]))
				len++;
			env_name = ft_substr(command, i + 1, len);
			//Proteger malloc
			if (ft_get_env_value(env_name))
				return (ft_get_env_value(env_name));
			else
				return ("ADIOS");
		}	
		i++;
	}
	return (NULL);
}

void	ft_substitute_env(void *list_elem)
{
	t_command	*content;

	content = (t_command *)list_elem;
	if (ft_have_env(content->command))
		content->command = ft_get_command_after_env(content->command);
}
