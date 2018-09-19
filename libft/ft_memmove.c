/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsavale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:24:25 by thsavale          #+#    #+#             */
/*   Updated: 2017/12/04 12:29:03 by thsavale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ndst;
	char	*nsrc;
	size_t		i;

	ndst = (char*)dst;
	nsrc = (char*)src;
	i = 0;
	if(nsrc < ndst)
	{
		while(len--)
			ndst[len] = nsrc[len];
	}
	else
		ft_memcpy(ndst, nsrc, len);
	return (ndst);
}
