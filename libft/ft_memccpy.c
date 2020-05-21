/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:00:35 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/05 15:09:52 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sorc;
	unsigned char	*dest;
	unsigned char	sc;

	i = 0;
	sorc = (unsigned char *)src;
	dest = (unsigned char *)dst;
	sc = (unsigned char)c;
	while (i < n)
	{
		dest[i] = sorc[i];
		if (dest[i] == sc)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
