#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_tetri
{
	char		**tetri;
	int			lettre;
	struct	s_tetri	 *next;
}					t_tetri;

int				count(char *path);
char			*record_file(char *path);
int				check_string(char *str);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strnew(size_t size);
char			**ft_resolve(t_tetri *begin);
int				ft_try_fill(char **sol, t_tetri *tmp, int x, int position);
char			**ft_fill(char **sol, t_tetri *tmp, int x, int position);
char			**ft_delete(char **sol, t_tetri *tmp, int x, int position);
t_tetri			*ft_lstnew_tetri(void);
t_tetri			*sort_tetri(char *str, int j);
int				check_tab(t_tetri *begin, int diese, int links);
void			upnleft(char **tab);

#endif
