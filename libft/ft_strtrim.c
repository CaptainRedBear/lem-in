/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:58:22 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/11 17:06:52 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	start = i;
	while (s[i])
		i++;
	i--;
	while (ft_iswhitespace(s[i]))
		i--;
	end = i;
	if ((int)end < (int)start)
		return (ft_strdup(""));
	if (!(str = ft_strnew(end - start + 1)))
		return (NULL);
	i = -1;
	while (++i + start <= end)
		str[i] = s[start + i];
	return (str);
}
