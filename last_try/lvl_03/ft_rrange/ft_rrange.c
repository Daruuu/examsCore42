/*
Assignment name  : ft_rrange
		Expected files   : ft_rrange.c
		Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
		values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int i;
	int len;
	int *result;

	i = 0;
	if (start < end)
		len = (end - start ) + 1;
	else
		len = (start - end) + 1;
	result = malloc(sizeof(int) * len);
	if (start <= end)
	{
		while (end >= start)
		{
			result[i] = end;
			end --;
			i ++;
		}
	}
	else
	{
		while (end <= start)
		{
			result[i] = end;
			i ++;
			end ++;
		}
	}
	return (result);
}

int main(void)
{
	int start = 4;
	int end = -9;
	int *res = ft_rrange(start, end);

	int len = end - start + 1;
	int i = 0;
	while (i < len)
	{
		printf("%d\n", res[i]);
		i ++;
	}
}