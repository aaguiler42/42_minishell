#include "minishell.h"

extern t_list	*g_env_vars;

void	ft_env(void)
{
	ft_lstiter(g_env_vars, print_env);
}

// This function recieves a string like "PATH=/bin" and adds it to the list of environment variables.
// TODO: Manage free of env (it can cause a double free)
void	ft_export(char *env)
{
	char	*previous_value;
	char 	*var_name;

	var_name = ft_substr(env, 0, ft_strchr(env, '=') - env);
	previous_value = ft_get_env_value(var_name);
	if(!previous_value)
	{
		free(var_name);
		ft_add_one_env(env);
	}
	else
	{
		ft_unset(var_name);
		ft_export(env);
		return ;
	}
	free(env);
}

void	ft_unset(char *env_name)
{
	char	*previous_value;
	char	*aux;
	char	*full_env;

	previous_value = ft_get_env_value(env_name);
	if(!previous_value)
	{
		ft_printf("minishell: unset: `%s': not a valid identifier\n", env_name);
		return ;
	}
	aux = ft_strjoin(env_name, "=");
	free(env_name);
	full_env = ft_strjoin(aux, previous_value);
	free(aux);
	free(previous_value);
	ft_list_remove_if(&g_env_vars, full_env, ft_strcmp);
	free(full_env);
}