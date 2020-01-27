/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 07:33:11 by hbarnard          #+#    #+#             */
/*   Updated: 2019/05/30 11:33:27 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	i = 0;
	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
		while ((int)(--len) >= 0)
			*(dest + len) = *(source + len);
	else if (!(dst == '\0' && src == '\0'))
		while (i < len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	return (dst);
}
