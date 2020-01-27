/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:22:30 by hbarnard          #+#    #+#             */
/*   Updated: 2019/05/30 11:32:11 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	int				i;

	i = 0;
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (n--)
	{
		if (s2[i] == c2)
			return (s2 + i);
		i++;
	}
	return (NULL);
}
