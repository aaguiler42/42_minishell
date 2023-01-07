#include "libft.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;

	if (!begin_list || !(*begin_list))
		return ;
	cur = *begin_list;
	if (cmp(cur->content, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur->content);
		free(cur);
		return ;
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}
