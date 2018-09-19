/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsavale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:24:59 by thsavale          #+#    #+#             */
/*   Updated: 2017/12/04 12:29:50 by thsavale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char nc;
	int i;

	nc = (char)c;
	i = 0;
	while((s[i] != nc) && (s[i] != '\0'))
		i++;
	if (s[i] == nc)
		return ((char *)s + i);
	return (NULL);
}
