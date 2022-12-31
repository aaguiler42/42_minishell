/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguiler < aaguiler@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:00:55 by aaguiler          #+#    #+#             */
/*   Updated: 2022/12/31 19:00:56 by aaguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	buffer[300];

	getcwd(buffer, 300);
	printf("%s\n", buffer);
}

void	ft_cd(char *path)
{
	char	buffer[300];
	char	*env;

	if (!path)
	{
		ft_printf("minishell: path to cd not set\n");
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_printf("minishell: cd: %s: No such file or directory\n", path);
		return ;
	}
	getcwd(buffer, 300);
	env = ft_strjoin("OLDPWD=", ft_get_env_value("PWD"));
	ft_export(env);
	env = ft_strjoin("PWD=", buffer);
	ft_export(env);
}

void	ft_echo(int argc, char **argv)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (argc > 1 && !ft_strcmp(argv[1], "-n"))
	{
		n = 1;
		i++;
	}
	while (i < argc)
	{
		ft_printf("%s", argv[i]);
		if (i < argc - 1)
			ft_printf(" ");
		i++;
	}
	if (!n)
		ft_printf("\n");
}
