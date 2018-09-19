#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *new;

	list = *alst;
	while (list)
	{
		new = list->next;
		del(list->content, list->content_size);
		free(list);
		list = new;
	}
	*alst = NULL;
}
