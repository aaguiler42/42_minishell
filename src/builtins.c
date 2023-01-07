/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:00:55 by aaguiler          #+#    #+#             */
/*   Updated: 2023/01/07 18:58:55 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pwd(int printable)
{
	char	*buffer;

	buffer = ft_calloc(300, 1);
	getcwd(buffer, 300);
	if (printable)
	{
		printf("%s\n", buffer);
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	ft_cd(char *path)
{
	// char	*pwd;
	// char	*old_pwd;
	// char	*buffer;

	if (!path)
	{
		printf("minishell: path to cd not set\n");
		return ;
	}
	if (chdir(path) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
		return ;
	}
	old_pwd = ft_strjoin("OLDPWD=", ft_get_env_value("PWD"));
	// TODO: comprobar malloc
	// ft_export(old_pwd);
	// TODO: comprobar malloc
	// buffer = ft_pwd(0);
	// TODO: comprobar malloc
	// pwd = ft_strjoin("PWD=", buffer);
	// ft_printf("PWD: %s\n", pwd);
	// TODO: comprobar malloc
	// ft_export(pwd);
	// TODO: comprobar malloc
}

void	ft_echo(char **argv)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (argv[1] && !ft_strcmp(argv[1], "-n"))
	{
		n = 1;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (!n)
		printf("\n");
}
