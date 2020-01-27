/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:07:51 by hbarnard          #+#    #+#             */
/*   Updated: 2019/05/30 11:40:40 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	dstl;

	dstl = ft_strlen(dst);
	i = 0;
	if (dstsize <= dstl)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (dstl + i) < dstsize - 1)
	{
		dst[dstl + i] = src[i];
		i++;
	}
	dst[dstl + i] = '\0';
	return (dstl + ft_strlen(src));
}
