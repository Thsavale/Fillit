#include "libft.h"

int		ft_isdigit(int c)
{
	if (((c >= 060) && (c <= 067)) || ((c >= 070) && (c <= 071)))
		return (1);
	else if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}
