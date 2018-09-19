#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int				i;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = malloc((ft_strlen(s) + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
