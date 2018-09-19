/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsavale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:23:55 by thsavale          #+#    #+#             */
/*   Updated: 2017/12/04 12:28:54 by thsavale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	unsigned char	*ndest;
	unsigned char	*nsrc;

	ndest = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	i = 0;
	while(i < n)
	{
		if((*ndest++ = *nsrc++) == (unsigned char)c)
			return(ndest);
		i++;
	}
	return (NULL);
}
