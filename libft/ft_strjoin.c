/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:04:09 by hbarnard          #+#    #+#             */
/*   Updated: 2019/06/06 09:04:23 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	strlens1;
	size_t	strlens2;

	if (s1 && s2)
	{
		strlens1 = ft_strlen(s1);
		strlens2 = ft_strlen(s2);
		if (!(join = (char *)malloc(strlens1 + strlens2 + 1)))
			return (NULL);
		j = 0;
		i = -1;
		while (++i < strlens1)
			join[i] = s1[i];
		while (j < strlens2)
			join[i++] = s2[j++];
		join[i] = '\0';
		return (join);
	}
	return (NULL);
}
