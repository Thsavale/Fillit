#include "libft.h"

t_list * ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new = f(lst);
	if(lst->next)
	{
		new->next = ft_lstmap(lst->next, f);
		if (new->next == NULL)
		{
			free(new);
			return (NULL);
		}
	}
	else
		new->next = NULL;
	return (new);
}
