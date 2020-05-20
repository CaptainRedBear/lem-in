/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:20:55 by cglanvil          #+#    #+#             */
/*   Updated: 2019/06/12 15:33:02 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		word;
	int		i;
	int		j;
	char	**str;

	if (!s || !c || !(str = (char **)malloc(sizeof(char*)
					* (ft_wordcount(s, c) + 1))))
		return (NULL);
	word = 0;
	i = 0;
	while (word < ft_wordcount(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (!(str[word] = (char *)malloc(sizeof(char)
						* (ft_wordlen(&s[i], c) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			str[word][j++] = s[i++];
		str[word][j] = '\0';
		word++;
	}
	str[word] = NULL;
	return (str);
}
