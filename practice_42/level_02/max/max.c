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

If the array is empty, the function returns 0.
*/
#include <stdio.h>
int		max(int* tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	i = 0;
	max = tab[i];
	while (i < (len - 1))
	{
		if (max < tab[i + 1])
			max = tab[i + 1];
		i ++;
	}
	return (max);
}

int	main(void)
{
	int	tab[10] = {123, 543,  -11, 5, 44, 0, 100};

	int	res = max(tab, 6);
	printf("%d\n", res);
	return (0);
}
