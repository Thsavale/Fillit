/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsavale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:25:38 by thsavale          #+#    #+#             */
/*   Updated: 2017/12/04 12:30:26 by thsavale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t max;

	if (*needle == '\0')
		return ((char *)haystack);
	max = ft_strlen(needle);
	while ((*haystack != '\0') && (max <= len))
	{
		if ((*haystack == *needle) && (ft_memcmp(haystack, needle, max) == 0))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
