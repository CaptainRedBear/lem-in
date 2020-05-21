/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:59:36 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/14 14:20:47 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;

	temp = NULL;
	if (lst)
	{
		temp = (t_list*)malloc(sizeof(t_list));
		if (!temp)
			return (NULL);
		temp = f(lst);
		temp->next = ft_lstmap(lst->next, f);
	}
	return (temp);
}
