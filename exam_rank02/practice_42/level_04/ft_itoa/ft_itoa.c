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
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int i;
	int len;
	char	*result;

	len = 0;
	if (nbr == -2147483648)
		return ("-2147483648\0");
	// -1234
	if (nbr <= 0)
		len ++;
	while (nbr)
	{
		nbr = nbr / 10;
		len ++;
	}
	result = malloc(sizeof(char *) * len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = "0";
		return (result);	//	"0"
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	//	1234
	//	len = 4
	while (nbr)
	{
		--len;
		result[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (result);
}
