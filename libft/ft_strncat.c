/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsavale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:25:28 by thsavale          #+#    #+#             */
/*   Updated: 2017/12/04 12:30:02 by thsavale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int max;

	j = 0;
	i = 0;
	max = (int)n;
	while (s1[i] != '\0')
		i++;
	while ((s2[j] != '\0') && (j < max))
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}