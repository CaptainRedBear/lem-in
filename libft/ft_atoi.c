/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:15:03 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/05 13:43:09 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *s)
{
	int neg;
	int num;
	int i;

	i = 0;
	neg = 1;
	num = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||
			s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - 48);
		i++;
	}
	return (num * neg);
}
