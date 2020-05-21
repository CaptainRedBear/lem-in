/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:23:27 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/05 15:12:14 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sorc;
	char	*dest;

	i = 0;
	sorc = (char *)src;
	dest = (char *)dst;
	if (!sorc && !dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}
