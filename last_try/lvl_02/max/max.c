/*
Assignment name  : max
		Expected files   : max.c
		Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

int		max(int* tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	if (len == 0)
		return (0);
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i ++;
	}
	return (max);
}
#include <stdio.h>

int	main(void)
{
	int	tab[10] = {23, 45 , 645, -11, 0, 543, 6, 555};
	printf("%d\n", max(tab, 8));
	return (0);
}
