/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:25:40 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/28 14:25:40 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lem_in.h"

void	mall_error(void)
{
	ft_putendl("Malloc error");
	exit(1);
}

void	dup_name(void)
{
	ft_putendl("Duplicate name");
	exit(1);
}

void	pos_clash(void)
{
	ft_putendl("Duplicate position");
	exit(1);
}
