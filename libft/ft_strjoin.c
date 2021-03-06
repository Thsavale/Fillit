#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((size + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, (char *)s1);
	ft_strcat(result, s2);
	return (result);
}
