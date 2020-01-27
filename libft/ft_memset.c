/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 07:53:13 by hbarnard          #+#    #+#             */
/*   Updated: 2019/05/30 11:31:53 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char*)b;
	while (i < len)
	{
		bb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
