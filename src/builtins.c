#include "minishell.h"

extern t_list	*g_env_vars;

void	ft_env(void)
{
	ft_lstiter(g_env_vars, print_env);
}

void 