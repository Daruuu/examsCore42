/*
Assignment name	: ft_strcspn
		Expected files	: ft_strcspn.c
		Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
		(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/
#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j ++;
		}
		i ++;
	}
	return (i);
}
