#include "fillit.h"

int		ft_lstsize(t_tetri *begin)
{
	int lst_size = 0;
	while (begin)
	{
		lst_size++;
		begin = begin->next;
	}
	return (lst_size);
}

char **ft_memcarre(char **sol, int x)
{
	int y;
	int z;

	y = x;
	z = 0;
	if (!(sol = malloc(sizeof(char *) * (x + 1))))
			return (NULL);
	while ((x - 1) >= 0)
	{
		sol[x - 1] = ft_strnew(y);
		while (z < y)
		{
			sol[x -1][z] = '.';
			z++;
		}
		sol[x - 1][z] ='\0';
		z = 0;
		x--;
	}
	sol[y] = ft_strnew(0);
	sol[y][0] = '\0';
	return (sol);
}

char	**ft_recursive(char **sol, t_tetri *begin, int x, int position)
{
	t_tetri *tmp;
	tmp = begin;
	if (!tmp)
		return (sol);
	while (position <= (x * x - 3))
	{
		if (ft_try_fill(sol, tmp, x, position))
		{
		sol = ft_fill(sol,tmp, x, position);
		if (ft_recursive(sol, tmp->next, x, 0))
			return (sol);
		sol = ft_delete(sol, tmp, x, position);
		}
		position++;
	}
	return (NULL);
}

char **ft_resolve(t_tetri *begin)
{
	char	**sol;
	int		lst_size;
	int		x;

	x = 2;
	lst_size = ft_lstsize(begin);
	while (x * x < 4 * lst_size)
		x++;
	sol = NULL;
	sol = ft_memcarre(sol, x);
	while (!(sol = ft_recursive(sol, begin, x, 0)))
	{
		x++;
		free(sol);
		sol = ft_memcarre(sol, x);
	}
	return (sol);
}
