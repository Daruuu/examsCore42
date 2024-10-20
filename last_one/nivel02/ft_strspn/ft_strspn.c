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
// verificar si cada caracter de "s" esta presente en "accept"
// comparar cada caracter de "s" con todos los caracteres en "accept" y
// contar cuantos caracteres iniciales de s pertenecen a "accept"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j;
	
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break;
			j ++;
		}
		if (accept[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

int main(void)
{
    const char *s = "abcde12345";
    const char *accept = "abc";
    size_t length = ft_strspn(s, accept);
    
    printf("Length of initial segment: %zu\n", length); // Salida: 3
    return 0;
}
