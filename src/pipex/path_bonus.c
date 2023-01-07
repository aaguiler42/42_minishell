/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:47:33 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/04 18:37:20 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

extern t_list	*g_env_vars;

char	*ft_path_is_ok(char *command, char *env_path)
{
	char	*path;
	char	*aux;

	aux = ft_strjoin(env_path, "/");
	if (!aux)
		return (NULL);
	path = ft_strjoin(aux, command);
	free(aux);
	if (!path)
		return (NULL);
	if (!access(path, X_OK))
		return (path);
	free(path);
	return (NULL);
}

int	ft_is_slash(size_t i, char c)
{
	(void)i;
	return (c == '/');
}

char	*ft_find_path(char *command, char **env_paths)
{
	char	**ptr;
	char	*path;

	if (ft_strsome(command, ft_is_slash))
		return (ft_strdup(command));
	ptr = env_paths;
	path = NULL;
	while (*ptr && !path)
	{
		path = ft_path_is_ok(command, *ptr);
		ptr++;
	}
	return (path);
}

char	**ft_get_env_paths(void)
{
	char	*path;
	char	**paths;

	path = ft_lstfind_fn(g_env_vars, "PATH=", ft_strncmp)->content;
	if (path)
		paths = ft_split(path + 5, ':');
	if (paths)
		return (paths);
	return (ft_calloc(1, sizeof(char *)));
}
