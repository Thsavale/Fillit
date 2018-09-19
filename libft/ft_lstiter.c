#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *new;

	while (lst)
	{
		new = lst->next;
		f(lst);
		lst = new;
	}
}
