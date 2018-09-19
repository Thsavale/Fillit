/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsavale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:25:40 by thsavale          #+#    #+#             */
/*   Updated: 2017/12/04 12:30:28 by thsavale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *nc;

	nc = (char *)s + ft_strlen(s);
	while(*nc != c)
	{
		if (nc == s)
			return (NULL);
		nc--;
	}
	return (nc);
}
