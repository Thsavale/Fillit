#include "fillit.h"

void		upnleft(char **tab)
{
	char *tmp;
	int		i;

	while (!ft_strcmp(tab[0],"....\0"))
	{
		tmp = tab [0];
		tab[0] = tab[1];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = tmp;
	}
	while (tab[0][0] == '.' && tab[1][0] == '.' &&tab[2][0] == '.' \
					&& tab[3][0] == '.')
	{
		i = 0;
		while (i < 4)
		{
			tab[i][0] = tab[i][1];
			tab[i][1] = tab[i][2];
			tab[i][2] = tab[i][3];
			tab[i][3] = '.';
			i++;
		}
	}
}
