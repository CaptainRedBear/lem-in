/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:08:29 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/06 12:12:01 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	test;

	if (!s1 || !s2)
		return (0);
	test = ft_strcmp(s1, s2);
	if (test == 0)
		return (1);
	else
		return (0);
}
