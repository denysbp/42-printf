#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *new_one;

	if (!new)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_one = ft_lstlast(*lst);
	new_one -> next = new;
}