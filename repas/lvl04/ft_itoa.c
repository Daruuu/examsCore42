//
// Created by daruuu on 10/25/24.
//
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int n;
	char *result;
	int len = 0;

	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr <= 0)
		len++;
	n = nbr;
	while (n)
	{
		n = n / 10;
		len++;
	}
	result = (char *) malloc(sizeof(char) * (len + 1 ));
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
		result[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (result);
}
