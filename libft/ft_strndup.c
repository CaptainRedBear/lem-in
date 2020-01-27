/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:49:56 by hbarnard          #+#    #+#             */
/*   Updated: 2019/07/03 10:17:11 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (s1[i] && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
