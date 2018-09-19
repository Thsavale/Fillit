#include "fillit.h"

int		ft_try_fill(char **sol, t_tetri *tmp, int x, int position)
{
	int i;
	int j;
	int pi;
	int pj;

	i = 0;
	j = 0;
	pi = position / x;
	pj = position % x;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tmp->tetri[i][j] == '#')
				if (!(sol[i + pi][j + pj]) || sol[i + pi][j + pj] != '.')
					return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

char	**ft_fill(char **sol, t_tetri *tmp, int x, int position)
{
	int i;
	int j;
	int pi;
	int pj;

	i = 0;
	j = 0;
	pi = position / x;
	pj = position % x;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tmp->tetri[i][j] == '#')
				sol[i + pi][j + pj] = tmp->lettre;
			j++;
		}
		i++;
		j = 0;
	}
	return (sol);
}

char	**ft_delete(char **sol, t_tetri *tmp, int x, int position)
{
	int i;
	int j;
	int pi;
	int pj;

	i = 0;
	j = 0;
	pi = position / x;
	pj = position % x;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tmp->tetri[i][j] == '#')
				sol[i + pi][j + pj] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return (sol);
}
