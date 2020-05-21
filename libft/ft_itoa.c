/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:18:53 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/06 16:35:27 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = n;
	len = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}
