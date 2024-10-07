/*
Assignment name  : ft_itoa
		Expected files   : ft_itoa.c
		Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/
#include <stdlib.h>

// caso min-max number
// vars: i, len, n
char	*ft_itoa(int nbr)
{
	int 	n;
	int 	len;
	int 	i;
	char	*result;

	len = 0;
	n = nbr;
	if (nbr == -2147483648)
		return ("-2147483648\0");
	if (nbr <= 0)
		len ++;
	while (n)
	{
		n = n / 10;
		len ++;
	}
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		result --;
	}
	return (result);
}

