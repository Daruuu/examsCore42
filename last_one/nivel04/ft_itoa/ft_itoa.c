/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	n;
	int	len;
	char	*result;

	len = 0;
	if (nbr == -2147483647)
		return ("-2147483647");
	if (nbr <= 0)
		len ++;
	n = nbr;
	while (n)
	{
		n = n / 10;
		len++;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len --;
	}
	return (result);
}
