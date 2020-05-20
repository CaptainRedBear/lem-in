/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:26:41 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/11 16:34:20 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	if (n == 0)
		return (0);
	i = 0;
	mem1 = (unsigned char*)s1;
	mem2 = (unsigned char*)s2;
	while (mem1[i] == mem2[i] && i < n - 1)
		i++;
	return (mem1[i] - mem2[i]);
}
