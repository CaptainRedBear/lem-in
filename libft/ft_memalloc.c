/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:53:21 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/05 15:10:25 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (!(mem = (void *)malloc(sizeof(void) * (size))))
		return (NULL);
	ptr = mem;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return (mem);
}
