/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:56:32 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/05 14:21:47 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sorc;
	unsigned char	cc;

	i = 0;
	sorc = (unsigned char*)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (sorc[i] == cc)
			return (sorc + i);
		i++;
	}
	return (NULL);
}
