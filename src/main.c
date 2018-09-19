#include "fillit.h"

t_tetri		*ft_lstnew_tetri(void)
{
	t_tetri		*new_element;
	int			i;

	i = 0;
	new_element = malloc(sizeof(t_tetri));
	if (!new_element)
		return (NULL);
	else
	{
		new_element->tetri = (char **)malloc(sizeof(char *) * 5);
		while (i < 4)
		{
			new_element->tetri[i] = (char *)malloc(5 *sizeof(char));
			i++;
		}
		new_element->tetri[4] = (char *)malloc(sizeof(char));
	}
	new_element->next = NULL;
	return (new_element);
}

char	*ft_strnew(size_t size)
{
	char		*book;
	unsigned int	i;

	i = 0;
	book = malloc(size + 1 * sizeof(char));
	if (book == NULL)
		return (0);
	while (i <= size)
	{
		book[i] = '\0';
		i++;
	}
	return (book);
}

void	ft_puttab(char **sol)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sol[i][j])
	{
		while (sol[i][j])
		{
			write(1 , &sol[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
		j = 0;
	}
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_tetri		*begin;
	t_tetri		*tmp;
	char		**sol;
	char		*str;

	if (argc == 2)
	{
		str = record_file(argv[1]);
		if (!check_string(str))
			ft_error();
		begin = sort_tetri(str, 'A');
		tmp = begin;
		while (tmp)
		{
			if (!check_tab(tmp, 0, 0))
				ft_error();
			upnleft(tmp->tetri);
			tmp = tmp->next;
		}
		sol = ft_resolve(begin);
		ft_puttab(sol);
	}
	else
		write(1, "usage: fillit target_file\n", 26);
	return (0);
}
