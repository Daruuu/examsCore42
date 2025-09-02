/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/
#include <stdlib.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j ++;
		}
		i ++;
	}
	return (NULL);
}
#include <stdio.h>


int	main(void)
{
	const char *str1 = "hello world";
	const char *str2 = "ow";
	char *result = ft_strpbrk(str1, str2);

	if (result)
		printf("First matching character: %c\n", *result);
	else
		printf("No matching characters found.\n");
	return 0;
}

