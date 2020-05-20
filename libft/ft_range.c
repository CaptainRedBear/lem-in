/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:27:30 by cglanvil          #+#    #+#             */
/*   Updated: 2019/05/27 10:30:50 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		i;
	int		diff;
	int		*ran;

	diff = max - min;
	if (diff <= 0)
	{
		return (NULL);
	}
	ran = (int*)malloc(sizeof(*ran) * (diff));
	i = 0;
	while (i < diff)
	{
		ran[i] = min + i;
		i++;
	}
	ran[i] = '\0';
	return (ran);
}
