/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 07:02:01 by hbarnard          #+#    #+#             */
/*   Updated: 2019/06/03 13:39:53 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		fnd;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	if (*haystack == '\0')
		return (NULL);
	while (haystack[i])
	{
		j = 0;
		fnd = 1;
		while (needle[j])
		{
			if (needle[j] != haystack[i + j])
				fnd = 0;
			j++;
		}
		if (fnd == 1)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
