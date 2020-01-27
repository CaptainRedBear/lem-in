/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:13:11 by hbarnard          #+#    #+#             */
/*   Updated: 2019/06/07 16:13:17 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long int	long_nbr;

	long_nbr = (long int)nbr;
	if (long_nbr < 0)
	{
		ft_putchar_fd('-', fd);
		long_nbr = -long_nbr;
	}
	if (long_nbr >= 10)
	{
		ft_putnbr_fd(long_nbr / 10, fd);
		ft_putnbr_fd(long_nbr % 10, fd);
	}
	else
		ft_putchar_fd(long_nbr + '0', fd);
}
