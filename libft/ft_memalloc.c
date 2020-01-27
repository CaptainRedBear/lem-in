/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:14:53 by hbarnard          #+#    #+#             */
/*   Updated: 2019/06/03 16:00:22 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if ((str = ((void *)malloc(size))) == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
	return (str);
}
