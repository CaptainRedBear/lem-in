/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:57:28 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/06 12:12:25 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	test;

	if (!s1 || !s2)
		return (0);
	test = ft_strncmp(s1, s2, n);
	if (test == 0)
		return (1);
	else
		return (0);
}
