/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:40:03 by hbarnard          #+#    #+#             */
/*   Updated: 2019/05/30 11:44:47 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	i = 0;
	if (dst == '\0' && src == '\0')
		return (NULL);
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (i < n)
	{
		*dest = *source;
		dest++;
		source++;
		i++;
	}
	return (dst);
}
