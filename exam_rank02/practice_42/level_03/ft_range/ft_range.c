/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	*range;
	int	len;

	len = 0;
	if (start < end)
		len = (len - start) + 1;
	else
		len = (start - end) + 1;
	range = (int *) malloc(sizeof(int) * len);
	if (!range)
		return (0);
	i = 0;
	while (i < len)
	{
		if (start < end)
		{
			range[i] = start;
			i ++;
			start ++;
		}
		else
		{
			range[i] = start;
			i ++;
			start --;
		}
	}
	return (range);
}

int	main(void)
{
	int	start;
	int	end;

	start = -11;
	end = 6;
	int	*res= ft_range(start, end);
	int	i = 0;
	while (res[i])
	{
		printf("%d ", res[i]);
		i ++;
	}
	return (0);
}
