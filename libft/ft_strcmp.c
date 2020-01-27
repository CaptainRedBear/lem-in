/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:31:51 by hbarnard          #+#    #+#             */
/*   Updated: 2019/05/31 09:34:02 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (c1[i] != '\0' && c2[i] != '\0')
	{
		if (c1[i] > c2[i])
			return (1);
		else if (c1[i] < c2[i])
			return (-1);
		i++;
	}
	return (c1[i] - c2[i]);
}
