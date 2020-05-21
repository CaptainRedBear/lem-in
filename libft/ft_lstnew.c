/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:42:35 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/13 12:09:26 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	temp = NULL;
	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
		temp->next = NULL;
	}
	else
	{
		if (!(temp->content = (void*)malloc(content_size)))
			return (NULL);
		temp->content = ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
		temp->next = NULL;
	}
	return (temp);
}
