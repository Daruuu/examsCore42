/*
Assignment name  : ft_strrev
		Expected files   : ft_strrev.c
		Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/
#include <unistd.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
	char	tmp;
	int 	i = 0;
	int 	len = 0;

	while (str[len] != '\0')
		len ++;
	// printf("i: %d len: %d\n", i, len);
	while (i < (len/2))
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i ++;
	}
	return (str);
}

int main() {
    char str[] = "Hello, World!";
    printf("Original: %s\n", str);
    ft_strrev(str);
    printf("Reversed: %s\n", str); // Salida: !dlroW ,olleH
    return 0;
}
