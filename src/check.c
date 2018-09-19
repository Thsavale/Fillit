#include "fillit.h"

int		check_string(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n' && str[i] != '#')
			return (0);
		if ((i + 1 - j) % 5 == 0 && str[i] != '\n')
			return (0);
		if ((i + 1) % 21 == 0 && str[i] != '\n')
			return (0);
		if ((i + 1) % 21 == 0)
			j++;
		i++;
	}
	if ((i + 1) % 21 != 0)
		return (0);
	return (1 + j);
}

t_tetri		*ft_list_push_back(t_tetri *begin_list)
{
	t_tetri *list;

	list = begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew_tetri();
		return (list->next);
	}
	else
		list = ft_lstnew_tetri();
	return (list);
}

t_tetri		*sort_tetri(char *str, int j)
{
	int		i;
	char	**tab;
	t_tetri	*tmp;
	t_tetri	*begin;

	begin = NULL;
	tab = ft_strsplit(str, '\n');
	i = 1;
	while (i <= 4 * check_string(str))
	{
		tmp = ft_list_push_back(begin);
		if(i == 1)
			begin = tmp;
		tmp->tetri[0] = tab[i - 1];
		tmp->tetri[1] = tab[i];
		tmp->tetri[2] = tab[i + 1];
		tmp->tetri[3] = tab[i + 2];
		tmp->tetri[4] = "\0";
		tmp->lettre = j;
		j++;
		i = i + 4;
	}
	tmp->next = NULL;
	return (begin);
}

int		count_link(int i, int j, char **tab)
{
	int		links;

	links = 0;
	if (tab[i][j + 1] == '#')
		links++;
	if (j != 0 && tab[i][j - 1] == '#')
		links++;
	if (i != 0 && tab[i - 1][j] == '#')
		links++;
	if (i != 3 && tab[i + 1][j] == '#')
		links++;
	return (links);
}

int		check_tab(t_tetri *begin, int diese, int links)
{
	t_tetri		*tmp;
	int		j;
	int		i;

	tmp = begin;
	i = -1;
	while (i++ < 4)
	{
		j = -1;
		while (j++ < 4)
		{
			if (tmp->tetri[i][j] == '#')
			{
				links = links + count_link(i, j, tmp->tetri);
				diese++;
			}
		}
	}
	if (links < 6 || diese != 4)
		return (0);
	return (1);
}
