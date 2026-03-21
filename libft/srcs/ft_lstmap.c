#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	/*
	DESCRIPTION :
	The function ft_lstmap creates a new list from a given list  by
	applying the function passed as parameter to the original list. If
	the memory allocation fails for any node in the new list, the new list
	will be deleted with the function passed as parameter and its memory
	will be freed.

	RETURN VALUE :
	The new list containing the new values if a functon was provided.
	A new copy of the list if no function was provided.
	NULL if the memory allocation failed.*/

	if (!lst)
	{
		return (NULL) ;
	}
	while (lst)
	{
		if (!f)
		{
			node = ft_lstnew(lst -> content);
		}
		else
		{
			node = ft_lstnew(f(lst -> content));
		}
		if (!node)
		{
			ft_lstclear(&new_list,del);
			return (NULL);
		}
		ft_lstadd_back(&new_list,node);
		lst = lst -> next;
	}
	return (new_list);
}