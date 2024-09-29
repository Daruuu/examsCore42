/*
 * Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/


#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	int	tmp;

	len = 0;
	while (str[len] != '\0')
		len ++;
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i ++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "hello, World!";

	char *res;
	res = ft_strrev(str);
	printf("%s\n", res);
	return (0);
}