/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:57:35 by cglanvil          #+#    #+#             */
/*   Updated: 2019/05/23 12:01:19 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int i;
	int test;

	i = 0;
	test = 1;
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9') ||
			(s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= 'A' && s[i] <= 'Z'))
		{
			if (test && (s[i] >= 'a' && s[i] <= 'z'))
				s[i] = s[i] - 32;
			else if (!test && (s[i] >= 'A' && s[i] <= 'Z'))
				s[i] = s[i] + 32;
			test = 0;
		}
		else
			test = 1;
		i++;
	}
	return (s);
}
