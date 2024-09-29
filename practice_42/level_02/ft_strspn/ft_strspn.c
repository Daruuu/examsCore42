#include <stdio.h>
/*
 * Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
 */

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	match;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		match = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				match = 1;
				break ;
			}
			j ++;
		}
		if (match == 0)
			break ;
		i ++;
	}
	return (i);
}


