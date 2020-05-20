/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:37:05 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/05 15:07:00 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sorc;
	char	*dest;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	sorc = (char*)src;
	dest = (char*)dst;
	if (sorc < dest)
		while ((int)(--len) >= 0)
			*(dest + len) = *(sorc + len);
	else
		while (++i < len)
			*(dest + i) = *(sorc + i);
	return (dst);
}
