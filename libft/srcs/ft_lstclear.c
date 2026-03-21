#include "libft.h"

/* Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_one;
	if (!lst || !del)
	{
		return ;
	}
	while (*lst)
	{
		next_one = (*lst) -> next;
		ft_lstdelone(*lst,del);
		*lst = next_one;
	}
	*lst = NULL;
}