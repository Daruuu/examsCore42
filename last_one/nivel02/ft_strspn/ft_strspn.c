/*
Assignment name	: ft_strspn
		Expected files	: ft_strspn.c
		Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
		(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	while (s[i] != '\0' && accept[i] != '\0')
	{
		if (s[i] == accept[i])
			i++;
		else
			return (i);
	}
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		size_t res = ft_strspn(av[1], av[2]);
		printf("%ld\n", res);
	}
	return  (0);
}
