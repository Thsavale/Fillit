#include "libft.h"

static const char	*ft_next(const char *s1, char c, int next)
{
	if (next)
		while ((*s1 != '\0') && (*s1 == c))
			s1++;
	else
		while ((*s1 != '\0') && (*s1 != c))
			s1++;
	return (s1);
}

static int		ft_leng(const char *s1, char c)
{
	int i;

	i = 0;
	while (*s1 != '\0')
	{
		s1 = ft_next(s1, c ,1);
		if (*s1 != '\0')
		{
			i++;
			s1 = ft_next(s1, c, 0);
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char **name;
	int		i;
	const char	*next;

	if (s == NULL)
		return (NULL);
	name = (char **)malloc(sizeof(char *) * (ft_leng(s, c) + 1));
	if (name == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_next(s, c, 0);
			name[i] = ft_strsub(s, 0, next - s);
			i++;
			s = next;
		}
	}
	name[i] = NULL;
	return (name);
}
