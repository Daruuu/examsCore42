#include <stdlib.h>
#include <stdio.h>


int     *ft_range(int start, int end) {
	int i;
	int len;
	int *range;

	if (start < end)
		len = (end - start) + 1;
	else
		len = (start - end) + 1;

	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (range);
}

/*
	if (start < end)
	{
		i = 0;
		while (start <= end)
		{
			range[i] = start;
			start ++;
			i ++;
		}
	}
	else
	{
		i = 0;
		while (start >= end)
		{
			range[i] = start;
			start --;
			i ++;
		}
	}
*/
