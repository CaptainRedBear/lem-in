/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:20:15 by cglanvil          #+#    #+#             */
/*   Updated: 2019/05/22 11:27:05 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		str_len;
	char	temp;

	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len / 2)
	{
		temp = s[i];
		s[i] = s[str_len - i - 1];
		s[str_len - i - 1] = temp;
		i++;
	}
	return (s);
}
