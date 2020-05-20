#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(*s2) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < (len))
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
