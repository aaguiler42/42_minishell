/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler <aaguiler@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:06 by aaguiler          #+#    #+#             */
/*   Updated: 2022/09/24 13:52:10 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_list	*g_env_vars;

void ft_add_one_env(char *env)
{
	char	*aux;
	t_list	*list_aux;

	aux = ft_strdup(env);
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
}

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
			return (ft_substr(content, ft_strlen(env) + 1, len));
		}
		env_vars = env_vars->next;
	}
	return (NULL);
}

char	*ft_get_cmd(char *command, int cont, int len, char *env)
{
	char	*c1;
	char	*c3;
	char	*command_aux;
	char	*final_command;

	c1 = ft_substr(command, 0, cont);
	c3 = ft_substr(command, cont + len + 1,
			ft_strlen(command) - cont - len - 1);
	free(command);
	if (env)
	{
		command_aux = ft_strjoin(c1, env);
		final_command = ft_strjoin(command_aux, c3);
		free(command_aux);
		free(env);
	}
	else
		final_command = ft_strjoin(c1, c3);
	free(c1);
	free(c3);
	return (final_command);
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
			while (command[i + len + 1] && ft_isalnum(command[i + len + 1]))
				len++;
			env_name = ft_substr(command, i + 1, len);
			command = ft_get_cmd(command, i, len, ft_get_env_value(env_name));
			free(env_name);
			i = -1;
		}
		i++;
	}
	return (command);
}

void	ft_substitute_env(void *list_elem)
{
	t_command	*content;
	int			i;

	i = 0;
	content = (t_command *)list_elem;
	while (content->command[i])
	{
		if (content->command[i] == '$' && content->command[i + 1]
			&& !ft_isspace(content->command[i + 1]))
		{
			content->command = ft_get_command_after_env(content->command);
			if (!content->command)
				content->command = ft_strdup("Malloc have failed");
			break ;
		}
		i++;
	}
}
