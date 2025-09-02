#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = 0;
	if (nbr == -2147483647)
		return ("-2147483647");
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
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}

		
}
